int pinOscilador = 2;
int pinBaseTransitor = 5;
int counterPeridoSenal = 0;
long peridoSenal = 0;
boolean senalOscilador = true;

long tiempoUltimaSenalOscilador = 0;

long periodoOscilador = 3;

int pinLed = 13;

void setup() {
   Serial.begin(9600);
   pinMode(pinOscilador, INPUT);
   pinMode(pinBaseTransitor, OUTPUT);
   pinMode(pinLed, OUTPUT);
   attachInterrupt(digitalPinToInterrupt(pinOscilador), oscilarLed, FALLING);

}

void loop() {
  digitalWrite(pinLed, senalOscilador);
  digitalWrite(pinBaseTransitor, senalOscilador);
}

void oscilarLed() {
    peridoSenal = millis() - tiempoUltimaSenalOscilador;
    tiempoUltimaSenalOscilador = millis();
    counterPeridoSenal++;

    if(counterPeridoSenal == periodoOscilador){ 
      senalOscilador = !senalOscilador;
      counterPeridoSenal = 0;
    }
    if (counterPeridoSenal == 1)
      Serial.println(peridoSenal );
}
