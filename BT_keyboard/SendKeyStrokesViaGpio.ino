/**
 * This example turns the ESP32 into a Bluetooth LE keyboard
 * 
 * Source https://arduinogetstarted.com/tutorials/arduino-button-library
 * and https://github.com/T-vK/ESP32-BLE-Keyboard
 */
#include <BleKeyboard.h>
#include <ezButton.h>

BleKeyboard bleKeyboard;

const int black_key = 19; //GPIO19
const int yellow_key = 21; //GPIO21

#define DEBOUNCE_TIME 50 // the debounce time in millisecond, increase this time if it still chatters

ezButton button1(black_key); // create ezButton object that attach to pin GIOP;
ezButton button2(yellow_key); // create ezButton object that attach to pin GIOP;


void setup() {
  button1.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  button2.setDebounceTime(DEBOUNCE_TIME); // set debounce time to 50 milliseconds
  
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}



void loop() {
  button1.loop(); // MUST call the loop() function first
  button2.loop(); // MUST call the loop() function first

if(bleKeyboard.isConnected()) {
  if (button1.isPressed()) {
    Serial.println("Sending 'b'...");
    bleKeyboard.print("b");
  }
//
//  if (button1.isReleased())
//    Serial.println("The button 1 is released");

  if (button2.isPressed())
  {
    Serial.println("Sending 'a'...");
    bleKeyboard.print("a");
  }

//  if (button2.isReleased())
//    Serial.println("The button 2 is released");  
}
}
