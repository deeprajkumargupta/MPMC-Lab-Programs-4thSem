#include<LPC21xx.h>

unsigned int delay;
unsigned int switchCount=0;
unsigned int Disp[16]= {0x003F0000, 0x00060000, 0x005B0000, 0x004F0000, 0x00660000, 0x006D0000, 0x007D0000, 0x00070000, 0x007F0000, 0x006F0000, 0x00770000, 0x007C0000, 0x00390000, 0x005E0000, 0x00790000, 0x00710000};
#define ALLDISP 0xF0000000
#define DATAPORT 0x00FF0000
int main(void)
{
    IO0DIR= 0XF0FF0000;
    PINSEL1= 0x00000000; //PINSEL1 contains PORT0 and pins P0.16 to P0.31
    while(1)
    {
        IO0SET= 0xF0000000;
        IO0CLR= 0x00FF0000;
        IO0SET= Disp[switchCount]; //get 7 segment display value from array
        for(delay=0; delay<1000000; delay++){}
        switchCount++;
        if(switchCount==0x10)
        {
            switchCount=0;
            IO0CLR=F0FF0000;
        }
    }
}