#include<lpc21xx.h>
void clock_wise(void);
void anti_clockwise(void);
unsigned long int var1;
unsigned int i=0;j=0;k=0;
int main(void)
{
    PINSEL0= 0x00000000;
    IO0DIR= 0x0000F000;
    while(1)
    {
        for(j=0;j<50;j++)
            clock_wise();
        for(k=0;k<65000;k++);
        for(j=0;j<50;j++)
            anti_clockwise();
        for(k=0;k<65000;k++);
    }
}
void clock_wise(void)
{
    var1= 0x00000800; //for clockwise
    for(i=0;i<=3;i++){ //for A B C D stepping
        var1= var1<<1; //for clockwise
        IO0PIN=var1;
        for(k=0;k<3000;k++); //for step speed variation
    }
}
void anti_clockwise(void)
{
    var1= 0x00010000; //for anticlockwise
    for(i=0;i<=3;i++){ //for A B C D stepping
        var1= var1<<1; //for anticlockwise
        IO0PIN=var1;
        for(k=0;k<3000;k++); //for step speed variation
    }
}