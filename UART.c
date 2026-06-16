#include<lpc21xx.h>
const char *msg= "hello world\r";
const char *ptr;
int main(void)
{
    PINSEL0= 0x00000005;
    U0LCR= 0x00000083;
    U0DLM= 0x00;
    U0DLL= 0x13;
    U0LCR= 0x00000003;
    while(1){
        while(*msg!=0x00){
            while(!(U0LSR & 0x20));
            U0THR=*msg;
            msg++;
        }
    }
}


steps:
1. open startup.s (in line 104 replace 0 to 1, and in line 128 replace 1 to 0)
2. flash-> configure flash tools-> inside output tab-> change name to uart
3. Ok, save, build
4. FlashMagic browse hexfile, static_assert
5. Go to tools -> Terminal-> Ok