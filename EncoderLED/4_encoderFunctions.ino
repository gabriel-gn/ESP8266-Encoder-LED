void handleKey() {
  isEncoderButtonPressed = true;
}

double encoderValueRead() {
  double encoderNewPosition = myEnc.read();
  if (encoderNewPosition != encoderOldPosition) {
    encoderOldPosition = encoderNewPosition;
  }
  if (encoderOldPosition >= 360) {
    myEnc.write(encoderOldPosition - 360);
  }
  if (encoderOldPosition <= 0) {
    myEnc.write(encoderOldPosition + 360);
  }
  return encoderNewPosition;
}

boolean encoderButtonPressed() {
  if (isEncoderButtonPressed && (millis() - lastUpdateEncoderMillis > 50)) {
    isEncoderButtonPressed = false;
    lastUpdateEncoderMillis = millis();
    Serial.println("Botão pressionado e soltado");
    return true;
  } else {
    return false;
  }
}
