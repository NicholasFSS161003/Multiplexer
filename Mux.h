#pragma once
#include <Arduino.h>

class Mux{
  private:
    uint8_t _selPin1,_selPin2,_selPin3,_selPin4;
    uint8_t _SIG;
     
  public:
    Mux(uint8_t selPin1,uint8_t selPin2,uint8_t selPin3,uint8_t selPin4,uint8_t SIG);
    void selectChannel(uint8_t selChannel);
    void getAngData(int arr[]);
    void getDigData(int arr[]);
    void showData(int arr[]);
};
