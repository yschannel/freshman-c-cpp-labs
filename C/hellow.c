#include <stdio.h>

void printHello(int count) {
  if(count == 0){
    return;
  }else{
    printf("Hello %d!\n",count);
    sleep_us(500000);
    printHello(count-1);
  }
    
}

int main() {
  printHello();
  return 0;
}