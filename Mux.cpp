#include "Mux.h"

Mux::Mux(uint8_t selPin1,uint8_t selPin2,uint8_t selPin3,uint8_t selPin4,uint8_t SIG):
_selPin1(selPin1),_selPin2(selPin2),_selPin3(selPin3),_selPin4(selPin4),_SIG(SIG){
  pinMode(_selPin1, OUTPUT);
  pinMode(_selPin2, OUTPUT);
  pinMode(_selPin3, OUTPUT);
  pinMode(_selPin4, OUTPUT);
  digitalWrite(_selPin1, LOW);
  digitalWrite(_selPin2, LOW);
  digitalWrite(_selPin3, LOW);
  digitalWrite(_selPin4, LOW);
  }

 void Mux::selectChannel(uint8_t selChannel)
 {
  int Bit0 = bitRead(selChannel, 0);
  int Bit1 = bitRead(selChannel, 1);
  int Bit2 = bitRead(selChannel, 2);
  int Bit3 = bitRead(selChannel, 3);
  digitalWrite(_selPin1, Bit0);
  digitalWrite(_selPin2, Bit1);
  digitalWrite(_selPin3, Bit2);
  digitalWrite(_selPin4, Bit3);
 }

 void Mux::getDigData(int arr[]){
    for (int i = 0; i < 16; i++) {
     selectChannel(i);
     if(analogRead(_SIG) == 1023)
        arr[i] = 1;
     else 
        arr[i] = 0;   
    }
 }

 void Mux::getAngData(int arr[]){
    for (int i = 0; i < 16; i++) {
     selectChannel(i);
     delay(10);
     arr[i] = analogRead(_SIG);
     delay(10);
  }
 }

 void Mux::showData(int arr[]){
    for (int i = 0; i < 16; i++) {
      if(i == 15){
        Serial.println(arr[i]);  
      }
      else{
        Serial.print(arr[i]);
        Serial.print(",");
      }
    }
  }
