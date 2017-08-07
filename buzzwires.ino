#include <CapacitiveSensor.h>

CapacitiveSensor buzzwire = CapacitiveSensor(7,2);        // 220K resistor between pins 7 & 2, pin 2 is sensor pin, add a wire and or foil if desired
void setup()                    
{
   buzzwire.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate
   Serial.begin(9600);
   pinMode(13, OUTPUT); // Set the on-board LED as indicator

}

void loop()                    
{
    
    long total =  buzzwire.capacitiveSensor(60); // Read the sensed capacitance summed over 60 samples

    if ( total > 50 ) { // 50 is the noise threshold
      digitalWrite(13, HIGH);  // Turn on onboard LED for 1s and turn it off again. 
      delay(1000);
      digitalWrite(13, LOW);
    }
    delay(100);                             // arbitrary delay
}
