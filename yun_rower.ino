#include <StackArray.h>
#include <Console.h>
#include <LiquidCrystal.h>
#include <Time.h>
#include <FileIO.h>
#include <Process.h>
const float Ratio = 4.8;
//const float Ratio = 1;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

/*-----------------SETUP--PINS-----------------------------*/
const int ROWERINPUT = 2; // the input pin where the waterrower sensor is connected
const int BUTTONSPIN = 0;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //lcd shield
StackArray <int> splits;
/*-----------------VARIABLES-----------------------------*/
volatile unsigned long click_time = 0;
volatile unsigned long last_click_time = 0;
volatile unsigned long old_split = 0;
volatile unsigned long split_time = 0;
volatile unsigned long start_split;
long debouncing_time = 15; //Debouncing Time in Milliseconds
volatile unsigned long last_micros;

volatile int clicks = 0;
volatile long rpm = 0;
volatile long old_rpm = 0;
int accel = 0;
volatile int Mm = 0;
volatile int meters = 0;
volatile int meters_old = 0;
volatile int trigger = 0;
unsigned long timer1 = 0;
unsigned long timer2 = 0;
String datestring;

/*-----------------SETUP-----------------------------------*/
void setup() {
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows:
  lcd.clear();
  lcd.home();
  Bridge.begin();
  Console.begin();
  Serial.begin(115200);
  lcd.print("Starting...");
  delay(1000);
  lcd.clear();
  lcd.print("Setup date...");
  delay(1000);
  Process date;
  date.begin("date");
  date.addParameter("+%F_%H-%M-%S");
  date.run();
  while (date.available() > 0) {
    char c = date.read();
    if (c != '\n') {
      datestring += c;
    }
  }
  lcd.clear();
  lcd.print(datestring);
  lcd.setCursor(0, 1);
  lcd.print("WaterRino 1.0");
  delay(4000);

  /*while (!Console) {
    ; // wait for Console port to connect.
    }*/
  //Console.println("You're connected to the Console!!!!");
  pinMode(ROWERINPUT, INPUT_PULLUP);
  digitalWrite(ROWERINPUT, HIGH);
  //delay(1000);
  attachInterrupt(1, rowerdebounceinterrupt, FALLING);
  timer1 = millis();
  timer2 = millis();
}

/*------------------LOOP-----------------------------------*/
void loop() {
  lcd.clear();
  lcd.home();
  lcd.print("Press Right to");
  lcd.setCursor(0, 1);
  lcd.print("Start");
  //while (analogRead (BUTTONSPIN) != 294) {
  while (read_LCD_buttons() != btnRIGHT) {
    //Serial.println(read_LCD_buttons());
  }
  row_start();
}



