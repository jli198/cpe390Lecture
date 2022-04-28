include "hcs12.inc"
ORG $4000
lds #$4800
ldx $1000 ;use X as data pointer
ldaa#4 ;sequence length = 4
jsr openAD0 ;initialize A/D converter
ldy #5 ;loop counter
loop5: movb #86, ATD0CTL5 ;start ch6 A/D conv. sequence
brclr ATD0STAT0,$80,* ;wait for sequence complete flag
movw ATD0DR0, 2,x+ ;collect and save results
movw ATD0DR1, 2,x+ ;incremeting pointer by 2
movw ATD0DR2, 2,x+
movw ATD0DR3, 2,x+
dbne y,loop5 ;are we done?
swi