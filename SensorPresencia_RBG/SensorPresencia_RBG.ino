
int pinFotoResistor = 2;
int pinR = 4;
int pinG = 5;
int pinB = 6;
int ledRGB[] = {pinR, pinG, pinB};
int binario[8][3] = { {1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}, {0,0,0} };
int contador = 0;
int ledDebug = 13;


void setup() {
  pinMode(pinFotoResistor, INPUT);
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(ledDebug, OUTPUT);
  representarBinarioEnRGB();
  attachInterrupt(digitalPinToInterrupt(pinFotoResistor), aumentarContador, RISING);
}

void loop() {

}

void aumentarContador() {
  digitalWrite(ledDebug, true);
  contador++;
  if (contador > 7)
    contador = 0;
  contarEnRGB();
  digitalWrite(ledDebug, false);
}

void contarEnRGB() {
 representarBinarioEnRGB();
}

void representarBinarioEnRGB() {
  for (int i = 0; i < 3; i++)
    digitalWrite(ledRGB[i], binario[contador][i]);
}

