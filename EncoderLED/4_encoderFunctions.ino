void handleKey() {
  isEncoderButtonPressed = true;
}

long encoderValueRead() {
  long encoderNewPosition = myEnc.read();
  if (encoderNewPosition != encoderOldPosition) {
    encoderOldPosition = encoderNewPosition;
  }
  return encoderNewPosition;
}

boolean encoderButtonPressed() {
  if (isEncoderButtonPressed && (millis() - lastUpdateEncoderMillis > 50)) {
    isEncoderButtonPressed = false;
    lastUpdateEncoderMillis = millis();
    // Reset the counter
    myEnc.write(0);
//    Serial.println("Botão pressionado e soltado");
    return true;
  } else {
    return false;
  }
}
