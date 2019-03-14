#include "SevSeg.h"
SevSeg sevseg; 

    // Initializes display number to start at 0
    int num = 0;
    const int motorPin = 9;
  
void setup(){
    Serial.begin(9600);

    // Sets up pin 9 to output power to the DC motor
    pinMode(motorPin, OUTPUT);

    // Sets up the 7 segment display library
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;
    
    // Sets beginning display to 0
    sevseg.setNumber(0);
    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){

    //  Sets the button variable to be read from pin A0
    int button = analogRead(A0);
    // Show what input the buttons are giving to the program
    Serial.println(button);
    delay(100);
    
    // Check if left button is pressed (Serial readout will be between 900-980)
    if (900 < button & button < 980) {
      // Increment the display +1
      sevseg.setNumber(num++); 
      // Refresh the display to show the newly incremented number 
      sevseg.refreshDisplay();
    }
    
    // Check if right button is pressed (Serial readout will be between 980-1020)
    if (980 < button & button < 1020) {
      // Increment the display -1
      sevseg.setNumber(num--);      
      sevseg.refreshDisplay();  
    } 

    // Resets the display number to 0 once it reaches above 9
    if (num == 10) {
      num = 0;
      sevseg.setNumber(num);
      sevseg.refreshDisplay();
    }

    // Resets the display number to 9 once it reaches below 0
    if (num == -1) {
      num = 9;
      sevseg.setNumber(num);
      sevseg.refreshDisplay();
    }

    // Turns on DC motor if the display is at 1
    if (num == 1) {
      digitalWrite(motorPin, HIGH); // turn the motor on (full speed)
      delay(700);
      sevseg.setNumber(num);
      sevseg.refreshDisplay();
    }  

}

