#include<lpc214x.h>
void clock_wise(void);
void anti_clockwise(void);
unsigned int j=0;
int main()
{
    PINSEL0= 0x00000000; //P0.0 to P0.15
    IO0DIR= 0x00000900;
    IO0SET= 0x00000100; //P0.8 should always be high 
    while(1)
    {
        clock_wise();
        for(j=0;j<400000;j++); //delay
        anti_clockwise();
        for(j=0;j<400000;j++); //delay
    }
}
void clock_wise(void)
{
    IO0CLR= 0x00000900;
    for(j=0;j<10000;j++);
    IO0SET= 0x00000900;
}
void anti_clockwise(void)
{
    IO0CLR= 0x00000900;
    for(j=0;j<10000;j++);
    IO0SET= 0x00000100;
    
}