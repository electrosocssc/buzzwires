#include <CapacitiveSensor.h>

long read_cap, max_cal = 0;
CapacitiveSensor buzzwire = CapacitiveSensor(7,2);        // 220K resistor between pins 7 & 2, pin 2 is sensor pin, add a wire and or foil if desired
void setup()                    
{
   buzzwire.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate
   Serial.begin(9600);
   pinMode(13, OUTPUT); // Set the on-board LED as indicator
   // Calibration

   for (int i = 0 ; i < 100 ; i++ ){
      read_cap = buzzwire.capacitiveSensor(60);
      max_cal = max_cal < read_cap? read_cap : max_cal;
   }
   

}

void loop()                    
{
    
    long total =  buzzwire.capacitiveSensor(60); // Read the sensed capacitance summed over 60 samples

    if ( total > max_cal + 50 ) { // 50 is the noise threshold
      digitalWrite(13, HIGH);  // Turn on onboard LED for 1s and turn it off again. 
      delay(1000);
      digitalWrite(13, LOW);
    }
    Serial.println(total);
    delay(100);                             // arbitrary delay
}
