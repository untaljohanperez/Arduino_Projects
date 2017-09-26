#include <TimerOne.h>

volatile boolean hayPeaton = false;
int botonPeatonPin = 2;

const int semaforoPeaton_LedVerdePin = 4;
const int semaforoPeaton_LedRojoPin = 5;

const int semaforoCarro_LedVerdePin = 6;
const int semaforoCarro_LedRojoPin = 7;

const long tiempoSemaforoPeaton = 3000000;
const long tiempoSemaforoCarro = 5000000;

const int tiempoDuracionGlishe = 200;
long contadorTiempoBotonPeaton = 0;

void setup() {
    configurarPines();
    inicializarSemaforos();
    configurarInterrupcionBotonPeaton();
    configurarInterrupcionSemaforoCarro();  
}

void loop() {
  
}

void configurarPines() {
    pinMode(botonPeatonPin, INPUT_PULLUP);
    pinMode(semaforoPeaton_LedVerdePin, OUTPUT);
    pinMode(semaforoPeaton_LedRojoPin, OUTPUT);
    pinMode(semaforoCarro_LedVerdePin, OUTPUT);
    pinMode(semaforoCarro_LedRojoPin, OUTPUT);
}

void configurarInterrupcionBotonPeaton() {
  attachInterrupt(digitalPinToInterrupt(botonPeatonPin), darPasoAlPeaton, LOW);
}

void configurarInterrupcionSemaforoCarro() {
    Timer1.initialize(tiempoSemaforoCarro);         
    Timer1.attachInterrupt(cambiarSemaforos);
}

void configurarInterrupcionSemaforoPeaton() {
  Timer1.initialize(tiempoSemaforoPeaton);
  Timer1.attachInterrupt(resetSemaforos); 
}

void darPasoAlPeaton() { 
  if (isSuperadoGliche()) {
    hayPeaton = true;
    contadorTiempoBotonPeaton = millis();
  } 
}

boolean isSuperadoGliche() {
    return millis() > contadorTiempoBotonPeaton + tiempoDuracionGlishe;
}

void ponerSemaforoEnRojo(int ledVerdePin, int ledRojoPin) {
  digitalWrite(ledVerdePin, LOW);
  digitalWrite(ledRojoPin, HIGH);
}

void ponerSemaforoEnVerde(int ledVerdePin, int ledRojoPin) {
  digitalWrite(ledVerdePin, HIGH);
  digitalWrite(ledRojoPin, LOW);
}

void cambiarSemaforos() {
  if (hayPeaton) {
      ponerSemaforoEnRojo(semaforoCarro_LedVerdePin, semaforoCarro_LedRojoPin);
      ponerSemaforoEnVerde(semaforoPeaton_LedVerdePin, semaforoPeaton_LedRojoPin);
      configurarInterrupcionSemaforoPeaton();
  } else {
    ponerSemaforoEnVerde(semaforoCarro_LedVerdePin, semaforoCarro_LedRojoPin);
    ponerSemaforoEnRojo(semaforoPeaton_LedVerdePin, semaforoPeaton_LedRojoPin);
    configurarInterrupcionSemaforoCarro();  
  }
}

void resetSemaforos() {
  hayPeaton = false;
  cambiarSemaforos();
}

void inicializarSemaforos() {
    ponerSemaforoEnVerde(semaforoCarro_LedVerdePin, semaforoCarro_LedRojoPin);
    ponerSemaforoEnRojo(semaforoPeaton_LedVerdePin, semaforoPeaton_LedRojoPin);
}