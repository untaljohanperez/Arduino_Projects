
//LABORATORIO #1

int PIN_Pulsador1 = 2;
int PIN_Pulsador2 = 4;
int PIN_Led1 = 3;
int PIN_Led2 = 5;

//Pines del display de 7 segmentos
int PIN_a = 7;
int PIN_b = 8;
int PIN_c = 9;
int PIN_d = 10;
int PIN_e = 11;
int PIN_f = 12;
int PIN_g = 13;
const long interval = 1000;
int digitoDisplay = 0;

byte seven_seg_display[10][7] = {
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

void setup() {
  pinMode(PIN_Pulsador1, INPUT);
  pinMode(PIN_Pulsador2, INPUT);
  pinMode(PIN_Led1, OUTPUT);
  pinMode(PIN_Led2, OUTPUT);

  // Asignación de las salidas display 7 segmentos
  pinMode(PIN_a, OUTPUT);  
  pinMode(PIN_b, OUTPUT);
  pinMode(PIN_c, OUTPUT);
  pinMode(PIN_d, OUTPUT);
  pinMode(PIN_e, OUTPUT);
  pinMode(PIN_f, OUTPUT);
  pinMode(PIN_g, OUTPUT);
}

void loop() {
  runPushButton();
  runCounterDelay();
}

void mostrarDisplay(byte digito)
{
  byte pin = (byte) PIN_a;
  for (byte segCount = 0; segCount < 7; segCount++) 
  {
    digitalWrite(pin, seven_seg_display[digito][segCount]);
    pin++;
  }
} 

void runCounterDelay() 
{
    for (byte i = 0; i < 10; i++) 
    {
     delay(interval);
     mostrarDisplay(i);
    }
}

void runPushButton() 
{
  int estadoPulsador1 = digitalRead(PIN_Pulsador1);
  int estadoPulsador2 = digitalRead(PIN_Pulsador2);
  
  if (estadoPulsador1 == HIGH)
  {
    digitalWrite(PIN_Led1, HIGH);
    digitalWrite(PIN_Led2, LOW);
  }
  
  if(estadoPulsador2 == HIGH)
  {
    digitalWrite(PIN_Led1, LOW);
    digitalWrite(PIN_Led2, HIGH);
  }
}
