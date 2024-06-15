#include "mbed.h"
#include <cstdio>
/*
a few words max 100. on the program.
*/

InterruptIn bluebtn(PC_13);
volatile int int_trig = 0;


void bttnFall(){
    int_trig = 1;
}

// main() runs in its own thread in the OS
int main()
{
    bluebtn.fall(&bttnFall);

    // this is a program for lab 1 embedded systems module
    while (true) {
        if(int_trig == 1){
            int_trig = 0;
            printf("bttnFall \r\n");

        }
    }
}

