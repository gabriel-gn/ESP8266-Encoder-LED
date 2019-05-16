void loop() {
//  Serial.println(encoderValueRead());
  hsvToRgb(abs(encoderValueRead()/360), 1, v);
  verifyButtonPress();
  delay(10); //de praxe
}
