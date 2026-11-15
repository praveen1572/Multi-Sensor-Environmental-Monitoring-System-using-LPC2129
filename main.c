#include"header.h"
//lm35 p0.27
//ldr p0.28 
//soil moisture p0.29
//water sensor p0.14
//green led p0.17
//yellow led P0.18
//red led p0.19
float temp,ldr,moisture;
unsigned int a,b,c,d;
int main(){
    IODIR0|=(1<<17)|(1<<18)|(1<<19);
    IOSET0|=(1<<17)|(1<<18)|(1<<19);	
    adc_init();
    uart0_init(9600);
    lcd_init();
    while(1){
        temp=get_temp();
        ldr=get_ldr();
        moisture=get_moisture();
        a=tempcheck(temp);
        b=ldr_check(ldr);
        c=moisture_check(moisture);
        d=water_check();
        if((a+b+c+d)==0){
            IOCLR0=(1<<17);
            IOSET0=(1<<18)|(1<<19);
            lcd_cmd(0x80);
            lcd_string("TEMP=");
            lcd_float(temp);
            lcd_cmd(0xC0);
            lcd_string("STATUS:SAFE");
        }
        else if((a==1)&&(b==0)&&(c==0)&&(d==0)){
            IOSET0=(1<<17)|(1<<19);
            IOCLR0=(1<<18);
            lcd_cmd(0x80);
            lcd_string("TEMP=");
            lcd_float(temp);
            lcd_cmd(0xC0);
            lcd_string("STATUS:HOT");
        }
        else{
            IOSET0=(1<<17)|(1<<18);
            IOCLR0=(1<<19);
            lcd_cmd(0x80);
            lcd_string("TEMP=");
            lcd_float(temp);
            lcd_cmd(0xC0);
            lcd_string("STATUS:DANGER");
        }
        uart_print_status();
        delay_ms(500);
    }
}
