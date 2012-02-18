
#include<msp430.h>


void delay()
{
unsigned int i = 0;
while(++i < 30000);
}


void adc_init()
{
ADC10CTL0 = ADC10ON | ADC10SHT_2 | SREF_0;
ADC10CTL1 = INCH_0 | SHS_0 | ADC10DIV_0 | ADC10SSEL_0 | CONSEQ_0 ;
ADC10AE0 = BIT0;
ADC10CTL0 |= ENC ;
}


void start_conversion()
{
ADC10CTL0 |= ADC10SC;
}


unsigned int converting()
{
return ADC10CTL1 & ADC10BUSY;
}


void greenon()
{
P1DIR=0x40;
P1OUT=0x40;
}

void greenoff()
{
P1OUT=0x00;
}

main()
{
 adc_init();

   while(1)
  {
      start_conversion();
      while(converting());
      
        if(ADC10MEM>380)
          greenoff();
            else
             greenon();
             delay();
      
  }
}
