#include <LiquidCrystal.h>

int input=A0;
int output=6;
int timepassed=0;
int resistance=20;
double Energy=0;
double total=0;
double gallonused=0;
double wtotal=0;
double trashmade=0;
double trtotal=0;
LiquidCrystal lcd(2, 3, 4, 5, 6,7);
void setup() {
  pinMode(input, INPUT);
  pinMode(output, OUTPUT);

    // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // initialize the serial communications:
  Serial.begin(9600);

  

  
  
}

void loop() {
  lcd.clear();
  lcd.print("power=");
  timepassed++;

 double recoTrash=10*timepassed;
 double randtrash=random(6,10);
 trashmade=trashmade+randtrash;
 double tratio=trashmade/recoTrash;
 double tdiff=1-tratio;
 double trtotal=trtotal+tdiff;
int trashpoints=trtotal*(1/16);

 
  double recoWater=(3.3*timepassed);
  double randwater=random(3,5);
  gallonused=(gallonused+randwater);
  double wratio=(gallonused/recoWater);
  double wdiff=1-wratio;
  wtotal=wtotal+wdiff;
int waterpoints=wtotal*0.15;

  
  double Voltage=analogRead(input)*5.0/1024;
  double Power=(Voltage*Voltage/resistance);
  lcd.print((int)(Power));
  lcd.print("kW");
  lcd.setCursor(0,1);
  lcd.print("energy used=");
  Energy= Energy+Power;
  double energyconsumed=10*Energy;
  double RecoValue=(100.0/24*timepassed);
  lcd.print(Energy);
  lcd.print("mWH");
  lcd.setCursor(0,2);
  lcd.print("recommended=");
  lcd.print(RecoValue);
  lcd.print("mWH");
  lcd.setCursor(0,3);
  double ratio=energyconsumed/RecoValue;
  double difference=1-ratio;
  total=total+difference;
int electricitypoints=total;
  if (total<0)
  {
    lcd.print("savings=");
    lcd.print(total*(-1));
    lcd.print("mWH");
    }
    else
  {
    lcd.print("wastage=");
    lcd.print(total);
    lcd.print("mWH");
  }
  delay(1000);



 
  

  
}
