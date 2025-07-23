#include <SoftwareSerial.h>
SoftwareSerial gprsSerial(5,4);
#include <String.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 6  // Connect DS18B20 Data pin to digital pin 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

 
// #include <Wire.h>
#include <LiFuelGauge.h>  // Library for MAX17043 battery fuel gauge
// Create an instance of the MAX17043 fuel gauge
LiFuelGauge gauge(MAX17043);


#include <TinyGPS++.h>
#define RXPin 3  // GPS Module TX to Arduino pin 3
#define TXPin 2  // GPS Module RX to Arduino pin 2
#define GPSBaud 9600
SoftwareSerial gpsSerial(RXPin, TXPin);
TinyGPSPlus gps;


void setup()
{
  gprsSerial.begin(9600);               // the GPRS baud rate   
  Serial.begin(9600);    // the GPRS baud rate 
 sensors.begin();
  delay(1000);

gauge.reset(); // Reset the fuel gauge
delay(200); // Allow time for initialization
gauge.setAlertThreshold(10); // Set low battery alert threshold to 10%


gpsSerial.begin(GPSBaud);
    //Serial.println("hello");


}
 
void loop()
{
   //---------------------------------------------

  sensors.requestTemperatures();
      float t = sensors.getTempCByIndex(0);
      float h = 25;
        float soc=gauge.getSOC();
      float volt=gauge.getVoltage();
      float longitude=0;
      float latitude=0;

for(int i=0;i<10;i++)
{
while (gpsSerial.available() > 0) {
        gps.encode(gpsSerial.read());
    }
    
    if (gps.location.isUpdated()) {
       float latitude = gps.location.lat();   // Store latitude 
       float longitude = gps.location.lng();  // Store longitude
       Serial.print("Latitude: "); 
       Serial.print(latitude, 6);  // Print latitude with 6 decimal places
       Serial.print(" | Longitude: ");
       Serial.print(longitude, 6); // Print longitude with 6 decimal places
    }
    delay(100);
}    
     
       Serial.print("SOC: "); // Print State of Charge (SOC)
       Serial.print(gauge.getSOC()); // Get battery percentage
       Serial.print("%, VCELL: ");
       Serial.print(gauge.getVoltage()); // Get battery voltage
       Serial.println("V"); // Print voltage value
      delay(100);   
         
      Serial.print("Temperature = ");
      Serial.print(t);
      Serial.println(" °C");
      Serial.print("Humidity = ");
      Serial.print(h);
      Serial.println(" %");    
      
   
  if (gprsSerial.available())
    Serial.write(gprsSerial.read());
 
  gprsSerial.println("AT");
  delay(1000);
 
  gprsSerial.println("AT+CPIN?");
  delay(1000);
 
  gprsSerial.println("AT+CREG?");
  delay(1000);
 
  gprsSerial.println("AT+CGATT?");
  delay(1000);
 
  gprsSerial.println("AT+CIPSHUT");
  delay(1000);
 
  gprsSerial.println("AT+CIPSTATUS");
  delay(2000);
 
  gprsSerial.println("AT+CIPMUX=0");
  delay(2000);
 
  ShowSerialData();
 
  gprsSerial.println("AT+CSTT=\"airtelgprs.com\"");  //start task and setting the APN, used "airtelgprs.com" only for airtel sim
  delay(1000);
 
  ShowSerialData();
 
  gprsSerial.println("AT+CIICR");//bring up wireless connection
  delay(3000);
 
  ShowSerialData();
 
  gprsSerial.println("AT+CIFSR");//get local IP adress
  delay(2000);
 
  ShowSerialData();
 
  gprsSerial.println("AT+CIPSPRT=0");
  delay(3000);
 
  ShowSerialData();
  
  gprsSerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");  //start up the connection with thingspeak
  delay(6000);
 
  ShowSerialData();
 
  gprsSerial.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();
  
  String str="GET https://api.thingspeak.com/update?api_key=................&field1="+ String(soc) +"&field2="+String(volt)+"&field3="+String(t)+"&field4="+String(longitude)+"&field5="+String(latitude); //In this line write your channel API_Key at the place of (................)
  Serial.println(str);
  gprsSerial.println(str);//begin send data to remote server
  
  delay(4000);
  ShowSerialData();
 
  gprsSerial.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet 
  gprsSerial.println();
 
  ShowSerialData();
 
  gprsSerial.println("AT+CIPSHUT");//close the connection
  delay(100);
  ShowSerialData();
  //--------------------------------------------------------
} 
void ShowSerialData()
{
  while(gprsSerial.available()!=0)
  Serial.write(gprsSerial.read());
  delay(5000); 
  
}
