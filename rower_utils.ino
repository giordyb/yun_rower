//reset function (set to select button)
void reset() {
  Serial.println("Reset");
  clicks = 0;
  meters = 0;
  meters_old = 0;
  click_time = 0;
  old_split = 0;
  split_time = 0;
  Mm = 0;
  timer1 = 0;
  timer2 = 0;
  old_split = millis();
  setTime(0, 0, 0, 0, 0, 0);
  lcd.clear();
}

int read_LCD_buttons()
{
  int adc_key_in = 0;
  adc_key_in = analogRead(BUTTONSPIN);      // read the value from the sensor
  delay(20); //switch debounce delay. Increase this delay if incorrect switch selections are returned.
  int k = (analogRead(BUTTONSPIN) - adc_key_in); //gives the button a slight range to allow for a little contact resistance noise
  if (5 < abs(k)) return btnNONE;  // double checks the keypress. If the two readings are not equal +/-k value after debounce delay, it tries again.
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;
  return btnNONE;  // when all others fail, return this...
}

