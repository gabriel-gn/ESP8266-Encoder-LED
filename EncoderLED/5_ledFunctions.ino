void hsvToRgb(double H, double S, double V) {
  //H, S and V input range = 0 -> 1.0
  //R, G and B output range = 0 -> 255

  if (S == 0) {
    r = V * 255;
    g = V * 255;
    b = V * 255;
  } else {
    double var_h = H * 6;
    if (H > 1) {
      var_h = 0; //H must be < 1

    }

    double var_i = (int) (var_h);
    double var_1 = V * (1 - S);
    double var_2 = V * (1 - S * (var_h - var_i));
    double var_3 = V * (1 - S * (1 - (var_h - var_i)));

    double var_r = 0;
    double var_g = 0;
    double var_b = 0;

    switch ((int) var_i) {
      case 0:
        var_r = V;
        var_g = var_3;
        var_b = var_1;
        break;
      case 1:
        var_r = var_2;
        var_g = V;
        var_b = var_1;
        break;
      case 2:
        var_r = var_1;
        var_g = V;
        var_b = var_3;
        break;
      case 3:
        var_r = var_1;
        var_g = var_2;
        var_b = V;
        break;
      case 4:
        var_r = var_3;
        var_g = var_1;
        var_b = V;
        break;
      default:
        var_r = V;
        var_g = var_1;
        var_b = var_2;
        break;
    }
    //1024 pois são os niveis que o esp8266 trabalha
    r = (int)(var_r * hueFactor);
    g = (int)(var_g * hueFactor);
    b = (int)(var_b * hueFactor);
  }

  normalizeColors(r, g, b);
  updateLedValues(r, g, b);

  Serial.print("R: \t"); Serial.print(r);
  Serial.print("\tG: \t"); Serial.print(g);
  Serial.print("\tB: \t"); Serial.println(b);
  Serial.print("H: \t"); Serial.print(h);
  Serial.print("\tS: \t"); Serial.print(s);
  Serial.print("\tV: \t"); Serial.println(v);
  Serial.println("---------------------------------------");
}

void updateLedValues(int R, int G, int B) {
  analogWrite(ledR, R);
  analogWrite(ledG, G);
  analogWrite(ledB, B);
}

void normalizeColors(int R, int G, int B) {
  int sum = R + G + B;
  if ( (sum / 3) > hueFactor ) {
    R = (int)(R * R / sum);
    G = (int)(G * G / sum);
    B = (int)(B * B / sum);
  }
}

void verifyButtonPress() {
  if (encoderButtonPressed()) {
    v -= brightnessFactor;
    if (v <= 0) {
      v = 1;
    }
  }
}
