int var_out;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
asm volatile(
  "LDI r19, 4 \n\t"
  "LDI r20, 10 \n\t"
  "LDI r21, 20 \n\t"
  "LDI r22, 30 \n\t"
  "MUL r21, r21 \n\t"
  "MOV r23, r0 \n\t"
  "MOV r24, r1 \n\t"
  "MUL r19, r20 \n\t"
  "MUL r0, r22 \n\t"
  "MOV r25, r0 \n\t"
  "MOV r26, r1 \n\t"
  "SUB r23, r25 \n\t"
  "SBC r24, r26 \n\t"
  "MOV %0, r23 \n\t"
  : "=r" (var_out)
  :
);
Serial.println(var_out);
}



