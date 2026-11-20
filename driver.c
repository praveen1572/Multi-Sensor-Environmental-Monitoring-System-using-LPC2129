#include"header.h"
float get_temp(void){
    unsigned int adc_val;
    float voltage;
    adc_val=adc_read(0);
    voltage=(adc_val*3.3)/1023;
    return voltage/0.01;
}
float get_ldr(void){
    unsigned int adc_val;
    adc_val=adc_read(1);
    return (adc_val*100)/1023;
}
float get_moisture(void){
    unsigned int adc_val;
    adc_val=adc_read(2);
    return (adc_val*100)/1023;
}
unsigned int tempcheck(float temp){
    if(temp<35)
        return 0;
    else if(temp<=40)
        return 1;
    else
        return 2;
}
unsigned int ldr_check(float ldr){
    if(ldr>=30)
        return 0;
    return 1;
}
unsigned int moisture_check(float moisture){
    if(moisture>=30)
        return 0;
    return 1;
}
unsigned int water_check(void){
    if(IOPIN0&(1 <<14))
        return 1;
    return 0;
}
void uart_print_status(void){
    uart0_tx_string("Temperature:");
    uart0_float(temp);
    uart0_tx_string("\r\n");
    uart0_tx_string("Light Level:");
    if(b==0)
        uart0_tx_string("NORMAL");
    else
        uart0_tx_string("DARK");
    uart0_tx_string("\r\n");
    uart0_tx_string("Soil Moisture:");
    uart0_float(moisture);
    uart0_tx_string(" %\r\n");
    uart0_tx_string("Water Sensor:");
    if(d==0)
        uart0_tx_string("NOT DETECTED");
    else
        uart0_tx_string("DETECTED");
    uart0_tx_string("\r\n");
    uart0_tx_string("System Status:");
    if((a+b+c+d)==0)
        uart0_tx_string("SAFE");
    else if((a==1)&&(b==0)&&(c==0)&&(d==0))
        uart0_tx_string("WARNING");
    else
        uart0_tx_string("DANGER");
    uart0_tx_string("\r\n");
    uart0_tx_string("LED:");
    if((a+b+c+d)==0)
        uart0_tx_string("GREEN");
    else if((a==1)&&(b==0)&&(c==0)&&(d==0))
        uart0_tx_string("YELLOW");
    else
        uart0_tx_string("RED");
    uart0_tx_string("\r\n\r\n");
}
