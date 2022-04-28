include "hcs12.inc"
ORG $4000
  lds #$4800
  movb $FF,DDRT ;set up Port T as 8-bit output
  ldaa #1 ;sequence length = 1
  jsr openAD0 ;initialize A/D converter
forever:	movb	#$87, ATD0CTL5		; start  ch7 A/D conv. sequence
	brclr	ATD0STAT0, $80, *	; wait for sequence complete flag
	ldd	ATD0DR0		; get 10 bit data
	ldy	#10		; multiply data by 10
	emul			; L.S. result in D
	addd	#31		; to round divisor
	ldx	#62		; divide by 62
	idiv			; quotient in X, rem in D
	tfr	x, d		; rounded quotient in D
	subd	#40		; to give signed result
	stab	PTT
	ldy	#2		; wait for 200 ms
	jsr	delayby100ms
	bra	forever