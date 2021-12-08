String UVIndexString = "0";
int UVIndex = 0;
int red = 10;
int yellow = 9;
int green = 8;

void setup() 
{
  Serial.begin(9600);
}
 
void loop() {
 
 int stringLength = 0; 
 UVIndexString = readSensor();
 Serial.print("UV Index: ");
 Serial.println(UVIndexString);
// Serial.println(stringLength);
 signalLED(UVIndex);
 delay(3000);
}


void signalLED(int uv) {
  if (uv <= 3) {
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  } else if (uv > 3 && uv < 7) {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
  } else {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
  }
}

String readSensor()
{
  int voltage = analogRead(A3);                        //connect UV sensor to Analog   
//  int voltage = ((sensorValue * 3.3) / 100);  //Voltage in miliVolts
//  Serial.print("Sensor Value: ");
//  Serial.println(sensorValue);
  Serial.print("Voltage: ");
  Serial.println(voltage);
  
  if(voltage < 50) {
    UVIndex = 0;
    UVIndexString = "0";
  } else if (voltage > 50 && voltage <= 227) {
    UVIndex = 0;
    UVIndexString = "0";
  } else if (voltage > 227 && voltage <= 318) {
    UVIndex = 1;
    UVIndexString = "1";
  } else if (voltage > 318 && voltage <= 408) {
    UVIndex = 2;
    UVIndexString = "2";
  } else if (voltage > 408 && voltage <= 503) {
    UVIndex = 3 ;
    UVIndexString = "3";
  } else if (voltage > 503 && voltage <= 606) {
    UVIndex = 4;
    UVIndexString = "4";
  } else if (voltage > 606 && voltage <= 696) {
    UVIndex = 5;
    UVIndexString = "5";
  } else if (voltage > 696 && voltage <= 795) {
    UVIndex = 6;
    UVIndexString = "6";
  } else if (voltage > 795 && voltage <= 881) {
    UVIndex = 7;
    UVIndexString = "7";
  } else if (voltage > 881 && voltage <= 976) {
    UVIndex = 8;
    UVIndexString = "8";
  } else if (voltage > 976 && voltage <= 1079) {
    UVIndex = 9;
    UVIndexString = "9";
  } else if (voltage > 1079 && voltage <= 1170) {
    UVIndex = 10;
    UVIndexString = "10";
  } else if (voltage > 1170) {
    UVIndex = 11;
    UVIndexString = "11";
  }
  return UVIndexString;
}
