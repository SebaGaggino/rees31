bool botonA;
bool botonB;
bool botonC;
bool finCarr;
bool trigg1 = 1;
float recorr = 0;
float recorrInicial = 300;
String strEntrada;
int modo = 1;
unsigned long millisAnt = 0;
unsigned long millisAct;
long intervalo = 2000;
int topeSup = 170;
int topeInf = 20;

void setup() {
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  Serial.begin(115200);
  delay(500);
  Serial.println("G92 X300");
  // loop inicial
  while (digitalRead(6) == LOW) {
    delay(10);
    recorrInicial -= 0.1;
    Serial.print("G1 X");
    Serial.print(recorrInicial);
    Serial.println(" F3000");
    digitalWrite(13, HIGH);
    delay(1);
  }
  Serial.println("G92 X0");
  Serial.print("G1 X");
  Serial.print(topeSup);
  Serial.println(" F10000");
  delay(intervalo);
}


void loop() {
  millisAct = millis();
  botonA = digitalRead(3);
  botonB = digitalRead(4);
  botonC = digitalRead(5);
  finCarr = digitalRead(6);
  if (botonA == LOW) {
    delay(100);
    modo = 1;
    intervalo = 2000;
  }
  if (botonB == LOW) {
    delay(100);
    modo = 2;
    intervalo = 1300;

  }
  if (botonC == LOW) {
    delay(100);
    modo = 3;
    intervalo = 700;

  }

  switch (modo) {
    case 1:
      if (millisAct - millisAnt >= intervalo) {
        millisAnt = millisAct;
        if (trigg1 == 1) {
          //Serial.println("G1 X20 F10000");
          Serial.print("G1 X");
          Serial.print(topeInf);
          Serial.println(" F10000");
          trigg1 = 0;
        }
        else {
          //Serial.println("G1 X150 F5000");
          Serial.print("G1 X");
          Serial.print(topeSup);
          Serial.println(" F5000");
          trigg1 = 1;
        }
      }
      break;
    case 2:
      if (millisAct - millisAnt >= intervalo) {
        millisAnt = millisAct;
        if (trigg1 == 1) {
          //          Serial.println("G1 X20 F20000");
          Serial.print("G1 X");
          Serial.print(topeInf);
          Serial.println(" F20000");
          trigg1 = 0;
        }
        else {
          //Serial.println("G1 X170 F10000");
          Serial.print("G1 X");
          Serial.print(topeSup);
          Serial.println(" F10000");

          trigg1 = 1;
        }
      }
      break;

    case 3:
      if (millisAct - millisAnt >= intervalo) {
        millisAnt = millisAct;
        if (trigg1 == 1) {
          //Serial.println("G1 X20 F40000");
          Serial.print("G1 X");
          Serial.print(topeInf);
          Serial.println(" F40000");
          trigg1 = 0;
        }
        else {
          Serial.println("G1 X170 F20000");
          Serial.print("G1 X");
          Serial.print(topeSup);
          Serial.println(" F20000");
          trigg1 = 1;
        }
      }
      break;


  }
}
