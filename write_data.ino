void writeperformancetosd() {
  Serial.println("writing to SD");
  int totaltime = ((minute() * 60) + second());
  String dataString;
  String splitsdatastring;
  dataString += datestring;
  dataString += ",";
  //dataString += minute();
  //dataString += ":";
  //dataString += second();
  dataString += totaltime;
  dataString += ",";
  dataString += meters;
  if (FileSystem.begin()) {
    Serial.println("filesystem begin OK");
  }
  else {
    Serial.println("filesystem begin error");
  }
  String clickstring;
  clickstring += datestring;
  clickstring += ",";
  clickstring += clicks;
  String splitsfilename;
  splitsfilename += "/mnt/sda1/arduino/www/";
  splitsfilename += datestring;
  splitsfilename += ".csv";
  char splitschar[50];
  splitsfilename.toCharArray(splitschar, 50);
  File dataFile = FileSystem.open("/mnt/sda1/arduino/www/datalog.csv", FILE_APPEND);
  File clicksFile = FileSystem.open("/mnt/sda1/arduino/www/clicks.csv", FILE_APPEND);
  File splitfile = FileSystem.open(splitschar, FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);
    clicksFile.println(clickstring);
    clicksFile.close();
    Serial.println(clickstring);
    Serial.println(splitschar);
    splitfile.println("splits");
    for (int x = 0; x < 16; x++) {
      if (!splits.isEmpty()) {
        splitfile.println(splits.pop());
      }
    }
    splitfile.close();
  }
  else {
    Serial.println("error datafile");
  }
  delay(1000);
}
