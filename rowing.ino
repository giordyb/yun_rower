void row_start() {
  lcd.clear();
  lcd.print("Ready");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print("Set");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("      ROW!!!     ");
  delay(1000);
  lcd.clear();
  reset();
  rowing();
}
void rowing() {
  while (read_LCD_buttons() != btnUP) {
    lcd.setCursor(0, 0);
    lcd.print("M ");
    lcd.print(meters);
    lcd.print(" ");
    /*accel = rpm - old_rpm;
      Serial.println(accel);
      if (accel < 0)
      lcd.print("U");
      if (accel > 0)
      lcd.print("D");
      old_rpm = rpm;*/
    lcd.setCursor(9, 0);
    lcd.print("Sp5 ");
    lcd.print(split_time);
    // set time display
    lcd.setCursor(0, 1);
    lcd.print("T ");
    if (minute() < 10)
      lcd.print("0");
    lcd.print(minute());
    lcd.print(":");
    if (second() < 10)
      lcd.print("0");
    lcd.print(second());
    lcd.setCursor(9, 1);
    lcd.print("M/m ");
    lcd.print(Mm);
    /* calculate meters/min*/
    if ((millis() - timer1) > 10000) {
      calcmetersmin();
      timer1 = millis();
      lcd.clear();
    }
    /*calculate split times every 500m*/
    if ((meters % 500) == 0 && meters > 0 ) {
      if ((millis() - timer2) > 1000) {
        split();
        lcd.clear();
      }
      timer2 = millis();
    }

    /* if select button is pressed reset */
    switch (read_LCD_buttons())
    {
      case btnSELECT:
        {
          reset();
          break;
        }
      case btnDOWN:
        {
          writeperformancetosd();
          break;
        }
    }

    if (random(0, 100) < 70)
      rowerinterrupt();
  }
}
/*------------------INTERRUPT-----------------------------------*/
void rowerinterrupt() {
  /*  if (trigger == 0) {
      reset();
      trigger = 1;
    }*/
  clicks++;
  meters = clicks / Ratio;
  //calcrpm();
}
/*------------------INTERRUPT END-----------------------------------*/

