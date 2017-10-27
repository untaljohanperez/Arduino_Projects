int pinFotoResistencia = 1;
int pinMotor = 3;

void setup() {
  Serial.begin(9600);
  pinMode(pinMotor, OUTPUT);
  pinMode(pinFotoResistencia, INPUT);
}

void loop() {
  Serial.println(analogRead(pinFotoResistencia)/4);
  analogWrite(pinMotor, analogRead(pinFotoResistencia)/4);
}
