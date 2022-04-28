include "hcs12.inc"
open AD0: movb $C0, ATD0CTL2
jsr wait20us ;wait for A/D circuits to stabilize
ldab #8
mult ;left shift sequence by 3 places
stab ATD0CTL3
movb #$01, ATD0CTL4
rts
wait20us: movb #$90, TSCR2 ;enable TCNT & fast timer clear
movb #0, TSCR1 ;set TCNT pre-scaler to 1
bset TIOS, $01 ;enable OC0
ldd TCNT ;start OC0 operation
addd #160 ;160 clock cycles = 20 us
std TC0
brclr TFLG1,$01,* ;wait for time-out
rts