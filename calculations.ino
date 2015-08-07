/*void calcrpm() {
  click_time = millis();
  rpm = (float)1000 / (click_time - last_click_time) * 60;
  last_click_time = click_time;
  }*/

//calculate meters per minute
void calcmetersmin() {
  Mm = (meters - meters_old) * 6;
  meters_old = meters;
  //Serial.println(Mm);
}

//calculate 500m split time (in seconds)
void split() {
  start_split = millis();
  split_time = (start_split - old_split) / 1000;
  old_split = millis();
  splits.push(split_time);
}


