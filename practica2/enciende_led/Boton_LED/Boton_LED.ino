
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  DDRB = DDRB|B10000000;  // Data direction Register B: Inputs 0-6, Output 7
}

void loop() {
  // put your main code here, to run repeatedly:
  asm volatile (
    "cbi %0, %1 \n"  //high
    "sbis %2, %3 \n"  //skip next if pin high
    "sbi %0, %1 \n" //low
    : : "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB7), "I" (_SFR_IO_ADDR(PINB)), "I" (PINB5):
 
    );
    
  delay(500);
 
 }
 


