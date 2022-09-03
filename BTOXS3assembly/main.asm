.include "/home/totli/m328Pdef.inc"
  
;Configuring pins 2-7 (PD2-PD7) of Arduino
;as output
  ldi r30,0b11111100
  out DDRD,r30
;Configuring pin 8 (PB0) of Arduino
;as output 
  ldi r30,0b00000001
  out DDRB,r30
  ldi r31,0b11000011
  out DDRB,r31
  ldi r31,0b11011111
  out PORTB,r31

  ldi r17,0b00000001
  ldi r18,0b00000001
  ldi r19,0b00000001
  ldi r20,0b00000001

 LSR r31
 LSR r31

AND r17,r31      ;r17=D
LSR r31
AND r18,r31      ;r18=C
LSR r31
AND r19,r31      ;r19=B
LSR r31
AND r20,r31      ;r20=A

 ldi r21,0b00000001
 eor r21,r17       ;r21=D'
 ldi r22,0b00000001
 eor r22,r18       ;r22=C'
 ldi r23,0b00000001
 eor r23,r19       ;r23=B'
 ldi r24,0b00000001
 eor r24,r20       ;r24=A'

mov r0,r20
AND r0,r23
AND r0,r22
mov r1,r24
AND r1,r19
AND r1,r17
mov r2,r24
AND r2,r19
AND r2,r18
OR  r0,r1
OR  r0,r2       ;r0=w
;mov r1,r24
;AND r1,r23
;AND r1,r17
mov r1,r24
AND r1,r23
AND r1,r18
mov r3,r23
AND r3,r22
AND r3,r17
mov r4,r24
AND r4,r19
AND r4,r22
AND r4,r21
OR  r1,r3
OR  r1,r4
;OR  r1,r4          ;r1=x
mov r2,r24
AND r2,r22
AND r2,r21
mov r3,r24
AND r3,r18
AND r3,r17
mov r4,r23
AND r4,r22
AND r4,r21
OR r2,r3
OR r2,r4           ;r2=y
mov r3,r24
AND r3,r21
;mov r4,r20
mov r4,r23
AND r4,r22
AND r4,r21
OR r3,r4            ;r3=z
ldi r25,0b00000001
eor r25,r0
ldi r26,0b00000001
eor r26,r1
ldi r27,0b00000001
eor r27,r2
ldi r28,0b00000001
eor r28,r3
mov r4,r25
AND r4,r1
AND r4,r27
AND r4,r28      ;r4=a
mov r5,r0
AND r5,r1
AND r5,r27
AND r5,r28
mov r6,r25
AND r6,r1
AND r6,r27
AND r6,r3
mov r7,r25
AND r7,r1
AND r7,r2
AND r7,r28
OR r5,r6
OR r5,r7        ;r5=b
mov r6,r0
AND r6,r1
AND r6,r27
AND r6,r28       ;r6=c
mov r7,r25
AND r7,r1
AND r7,r27
AND r7,r28
mov r8,r25
AND r8,r1
AND r8,r2
AND r8,r3
mov r9,r0
AND r9,r26
AND r9,r2
AND r9,r28
OR r7,r8
OR r7,r9        ;r7=d
mov r8,r25
AND r8,r2
AND r8,r3
mov r9,r25
AND r9,r1
AND r9,r27
mov r10,r0
AND r10,r26
AND r10,r27
AND r10,r3
OR r8,r9
OR r8,r10         ;r8=e
mov r9,r25
AND r9,r2
AND r9,r3         ;r9=f
mov r10,r25
AND r10,r1
AND r10,r2
AND r10,r3
mov r11,r0
AND r11,r1
AND r11,r27
AND r11,r28
or r10,r11           ;r10=g

mov r30,r9
LSL r30
OR r30,r8
LSL r30
OR r30,r7
LSL r30
OR r30,r6
LSL r30
OR r30,r5
LSL r30
OR r30,r4
LSL r30
LSL r30
out PortD,r30

mov r30,r10
out PortB,r30
Start:
  rjmp Start


