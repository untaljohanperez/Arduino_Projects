
int pinFotoResistor = 2;
int pinMotor = 4;
boolean estadoMotor = true;


void setup() {
  pinMode(pinFotoResistor, INPUT);
  pinMode(pinMotor, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pinFotoResistor), cambiarEstadoMotor, CHANGE); 
}

void loop() {
  digitalWrite(pinMotor, estadoMotor);
}

void cambiarEstadoMotor() {
  estadoMotor = !estadoMotor;
}

