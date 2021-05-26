#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "mainPage.h"


const char *ssid = "Magnes";
const char *password = "12345678";
int count = 0;
String updated_value = "Your input Watt Hours are ";
String charge_text = "\nYour Charge is Rs. ";
String back_button = "\nYou may press back now";

int wattHours;
int charge_per_unit = 10;
WebServer server(80);
String wattHours_s;

void handleRoot() {
  String s = MAIN_page;
  
  
  server.send(200, "text/html", s);
}

void handleForm() {
  
  
  //String s = MAIN_page;
  //s.replace("@@WATTHOUR@@", required_watt_hour_value);
  
  String required_watt_hour_value = server.arg("required_watt_hour_value"); //Obtaining input from form on server
  wattHours = required_watt_hour_value.toInt(); 
  
  String charge_value = String(wattHours * charge_per_unit); 
  //s.replace("@@COST@@", charge_value);
  
  Serial.printf("\nYour input Watt Hours are : %d",wattHours);
  //server.sendHeader("Location", "/");
  server.send(200, "text/plain", updated_value + required_watt_hour_value + charge_text + charge_value + back_button); //Sending Charge as text to Server
  //server.send(302,"text/html",s);

  delay(500);
    
  }


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");
  
  WiFi.softAP(ssid, password); //Configuring esp32 as SoftAP (Hotspot)
  IPAddress myIP = WiFi.softAPIP();
  Serial.println(myIP); //IP address of esp32 AP

  //Server Setup
  server.on("/", handleRoot); //handleRoot function will be called on searching http:192.168.4.1/ in the browser
  server.on("/form", handleForm); //handleForm function will be called on clicking submit on the form

  //Server begin
  server.begin(); 
  
  Serial.printf("Connected devices are : %d",WiFi.softAPgetStationNum());

}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.softAPgetStationNum()!= 0){
    if (count == 0){
      Serial.printf("\nConnected devices are : %d",WiFi.softAPgetStationNum());
      count++;
    }
    
  }
  
  server.handleClient();

}
