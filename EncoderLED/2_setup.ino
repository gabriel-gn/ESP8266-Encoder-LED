void setup() {
  //encoder
  pinMode(D4, INPUT_PULLUP);
  attachInterrupt(D4, handleKey, RISING);

  //led
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);

  //serial
  Serial.begin(115200);
  Serial.println("Basic Encoder Test:");
}
