include "hcs12.inc"
CR: equ $0D ;ascii carriage return
LF: equ $0D ;ascii line feed
ORG $5000
headbuf:dc.b"Voltage=",0
numbuf:dc.b"0.0 V", CR, LF, 0 ;calculated digits stored here
ORG $4000
lds #$4800
ldaa#1  ;sequence length = 1
jsr openAD0 ;initialize A/D converter
forever: movb #$83, ATD0CTL5  ;start ch3 A/D conv. sequence
brclr ATD0STAT0, $80,*  ;wait for sequence compelte flag
ldd ATD0DR0 ;get 10 bit data
ldy #10 ;multiply data by 10
emul  ;L.S. result in D
ldx #2046 ;divide by 2046
idiv  ;quotient in X, rem in D
exg x,d ;swap X and D
addd #$30 ;convert MSD to ascii
stab numbuf ;store in string buffer
tfr x,d ;remainder back in D
ldy #10 ;multiply remainder by 10
emul
ldx #2046 ;and divide by 2046
idiv  ;quotient in X
tfr x,d ;fractional digit in D
addd #$30 ;convert LSD to ascii
stab numbuf+2 ;store in string buffer
ldx #headbuf
jsr putsSCI0  ;output header string
ldx #numbuf
jsr putsSCI0  ;output number string
ldy #20
jsr delayby100ms  ;wait for 2 seconds
bra forever