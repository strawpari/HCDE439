#include "SevSeg.h"
SevSeg sevseg; 

void setup(){
    Serial.begin(9600);

    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
    Serial.println(analogRead(A0));
    delay(100);
    
    sevseg.setNumber(0);
    sevseg.refreshDisplay();        
}

