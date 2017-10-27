const byte pin1 = 7;
const byte pin2 = 6;
const byte pin3 = 5;
const byte pin4 = 4;
const byte pinLed = 9;

byte valor1;
byte valor2;
byte valor3;
byte valor4;

void setup() {
  Serial.begin(9600);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  int valor = xxx();
  analogWrite(pinLed, valor); 
}

int xxx() {
  valor1 = digitalRead(pin1); // 1
  valor2 = digitalRead(pin2); // 1
  valor3 = digitalRead(pin3); // 0
  valor4 = digitalRead(pin4); // 0

  int representacionDecimal = (valor1 * pow(2, 0)) + (valor2 * pow(2, 1)) + (valor3 * pow(2, 2)) + (valor4 * pow(2, 3));
  Serial.println(representacionDecimal);
  return representacionDecimal * 255 / 15;
}
