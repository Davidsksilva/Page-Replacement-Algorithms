#include <iostream>
#include "pra.hpp"
int main(){

  PRA pra("input2.txt");
  pra.FIFO();
  pra.OTM();
  pra.LRU();
  return 0;
}
