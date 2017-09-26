int pinA = 7;
int pinB = 8;
int pinC = 9;
int pinD = 10;
int pinE = 11;
int pinF = 12;
int pinG = 13;

byte displaySieteSegmentos[7] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG};

int pinBotonSumar = 2;
int pinBotonRestar = 3;

int digitoDisplay = 0;

byte combinacionesNumerosDisplay[10][7] = {
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0}
};

const int tiempoGlitch = 200;
long ultimoIncremento = 0;
long ultimaDisminucion = 0;

void setup() {
  configurarDisplay();
  configurarBotones();
  configurarInterrupcionesBotones();
  
}

void loop() {
  pintarDigitoDisplay(digitoDisplay);
}

void configurarBotones() {
  pinMode(pinBotonSumar, INPUT);
  pinMode(pinBotonRestar, INPUT);
}

void configurarDisplay() {
  for (int i = 0; i < 7; i++)
    pinMode(displaySieteSegmentos[i], OUTPUT);
}

void configurarInterrupcionesBotones() {
  attachInterrupt(digitalPinToInterrupt(pinBotonSumar), incrementarDigitoDisplay, FALLING);
  attachInterrupt(digitalPinToInterrupt(pinBotonRestar), dismunirDigitoDisplay, FALLING);
}

void incrementarDigitoDisplay() {
  if (isSuperadoGlitch(ultimoIncremento) && digitoDisplay < 5) {
    digitoDisplay++;   
    ultimoIncremento = millis();
  }
}

void dismunirDigitoDisplay() {
  if (isSuperadoGlitch(ultimaDisminucion) && digitoDisplay > 0) {
    digitoDisplay--;  
    ultimaDisminucion = millis();
  }
}

boolean isSuperadoGlitch(long ultimoEvento) {
    return millis() > ultimoEvento + tiempoGlitch;
}

void pintarDigitoDisplay(byte digito) {
  byte pinDisplay = (byte) pinA;
  for (byte segmento = 0; segmento < 7; segmento++) {
    digitalWrite(pinDisplay, combinacionesNumerosDisplay[digito][segmento]);
    pinDisplay++;
  }
}
