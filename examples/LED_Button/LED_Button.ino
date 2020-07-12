/* MCP23008_ESP example.
 * Set custom SDA and SCL pins for initializing the MCP
 * Use a button to toggle an LED
*/

// Sourced from: https://RandomNerdTutorials.com/esp32-digital-inputs-outputs-arduino/
#include <Wire.h>
#include <SPI.h>
#include "MCP23008_ESP.h"

// set pin numbers
const int BUTTON = 1;  // the MCP23008 pin number of the pushbutton
const int LED =  0;    // the MCP23008 pin number of the LED
const int MCP_SDA = 13;
const int MCP_SCL = 15;

Adafruit_MCP23008 mcp;
// variable for storing the pushbutton status 
int buttonState = 0;

void setup() {
  Serial.begin(115200); 
  
  //init mcp
  mcp.begin(0, MCP_SDA, MCP_SCL); //** using overloaded begin() function with (addr, SDA, SCL)
  mcp.pinMode(BUTTON,INPUT);
  mcp.pullUp(BUTTON, HIGH);
  mcp.pinMode(LED, OUTPUT);
  Serial.println("LED and Button pins set!");
}

void loop() {
  Serial.println("Reading button");
  // read the state of the pushbutton value
  buttonState = mcp.digitalRead(BUTTON);
  Serial.println(buttonState);
  
  // check if the pushbutton is pressed.
  if (buttonState == HIGH) {
    // turn LED on
    Serial.println("LED ON");
    mcp.digitalWrite(LED, HIGH); //turn led on
  } 
  else {
    // turn LED off
    Serial.println("LED OFF");
    mcp.digitalWrite(LED, LOW); //turn led off
  }
  delay(400);
  
}