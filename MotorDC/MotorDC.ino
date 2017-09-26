int pinBotonMotor = 2;
int pinLed = 13;
int pinMotor = 4;
boolean estadoMotor = false;

const int tiempoDuracionGlishe = 200;
long contadorGlishe = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pinBotonMotor, INPUT_PULLUP);
    pinMode(pinMotor, OUTPUT);
    pinMode(pinLed, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(pinBotonMotor), cambiarEstadoMotor, FALLING);
    digitalWrite(pinLed, estadoMotor);
    digitalWrite(pinMotor, estadoMotor);
} 

void loop() {

}

void cambiarEstadoMotor(){
  if (isSuperadoGliche()) {
    estadoMotor = !estadoMotor;
    Serial.println(estadoMotor);
    digitalWrite(pinLed, estadoMotor);
    digitalWrite(pinMotor, estadoMotor);
    contadorGlishe = millis();
  }
}

boolean isSuperadoGliche() {
    return millis() > contadorGlishe + tiempoDuracionGlishe;
}
 

