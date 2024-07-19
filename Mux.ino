#include "Mux.h"
int mux_state[16] = {0};
Mux helloMux(7,6,5,4,A0);

void setup() {
  // put your setup code here, to run once:
   
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //helloMux.selectChannel(0);
  //Serial.println(analogRead(A0));
  helloMux.getAngData(mux_state);
   helloMux.showData(mux_state);
}
