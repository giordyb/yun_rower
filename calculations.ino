/*void calcrpm() {
  click_time = millis();
  rpm = (float)1000 / (click_time - last_click_time) * 60;
  last_click_time = click_time;
  }*/

//calculate and return meters per second
float calcmetersmin() {
  float x = (clicks - clicks_old) / Ratio;
  clicks_old = clicks;
  return x; 
}

//calculate 500m split time (in seconds)
void split() {
  start_split = millis();
  split_time = (start_split - old_split) / 1000;
  old_split = millis();
  splits.push(split_time);
}


