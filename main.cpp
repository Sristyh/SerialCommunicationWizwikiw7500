#include "mbed.h"

DigitalOut green(D10);
DigitalOut red(D12);
DigitalOut yel(D11);
//DigitalIn cube(D8);
InterruptIn cube(D8);

Serial pc(USBTX,USBRX);

char data;

void button_handler() {
   pc.printf("1");
   pc.putc(1);
}

int main() {
    //int cubestate;
    cube.rise(&button_handler);
    pc.baud(9600);
   // pc.printf("Hello");
    
    
    while(true)
 {
    //cubestate = cube;
//    while(cubestate == 1)
//   {
//       pc.printf("HIIIIIIIIIIIIII");
//   }
    
    data=pc.getc();
    if(data == 'G')
    {
        green=1;
        yel=0;
        red=0;
     } 
       
     if(data == 'Y')
    {
        green=0;
        yel=1;
        red=0;
    }
     if(data == 'R')
    {
        green=0;
        yel=0;
        red=1;
    }
        
     if(data == 'X')
     { 
        green=0;
        yel=0;
        red=0;
        
       } 
    }
}
