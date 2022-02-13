	.arch armv8-a
	.file	"test.cc"
	.text
	.align	2
	.p2align 4,,11
	.global	_Z3addii
	.type	_Z3addii, %function
_Z3addii:
.LFB1592:
	.cfi_startproc
	add	w0, w0, w1
	ret
	.cfi_endproc
.LFE1592:
	.size	_Z3addii, .-_Z3addii
	.align	2
	.p2align 4,,11
	.global	_Z3addmm
	.type	_Z3addmm, %function
_Z3addmm:
.LFB1593:
	.cfi_startproc
	add	x0, x0, x1
	ret
	.cfi_endproc
.LFE1593:
	.size	_Z3addmm, .-_Z3addmm
	.align	2
	.p2align 4,,11
	.global	_Z3subii
	.type	_Z3subii, %function
_Z3subii:
.LFB1594:
	.cfi_startproc
	sub	w0, w0, w1
	ret
	.cfi_endproc
.LFE1594:
	.size	_Z3subii, .-_Z3subii
	.align	2
	.p2align 4,,11
	.global	_Z3mulii
	.type	_Z3mulii, %function
_Z3mulii:
.LFB1595:
	.cfi_startproc
	mul	w0, w0, w1
	ret
	.cfi_endproc
.LFE1595:
	.size	_Z3mulii, .-_Z3mulii
	.align	2
	.p2align 4,,11
	.global	_Z6divideii
	.type	_Z6divideii, %function
_Z6divideii:
.LFB1596:
	.cfi_startproc
	sdiv	w0, w0, w1
	ret
	.cfi_endproc
.LFE1596:
	.size	_Z6divideii, .-_Z6divideii
	.align	2
	.p2align 4,,11
	.global	_Z7mul_addiii
	.type	_Z7mul_addiii, %function
_Z7mul_addiii:
.LFB1597:
	.cfi_startproc
	madd	w0, w0, w1, w2
	ret
	.cfi_endproc
.LFE1597:
	.size	_Z7mul_addiii, .-_Z7mul_addiii
	.align	2
	.p2align 4,,11
	.global	_Z7add_muliii
	.type	_Z7add_muliii, %function
_Z7add_muliii:
.LFB1598:
	.cfi_startproc
	add	w0, w0, w1
	mul	w0, w0, w2
	ret
	.cfi_endproc
.LFE1598:
	.size	_Z7add_muliii, .-_Z7add_muliii
	.align	2
	.p2align 4,,11
	.global	_Z8is_primem
	.type	_Z8is_primem, %function
_Z8is_primem:
.LFB1599:
	.cfi_startproc
	cmp	x0, 2
	bls	.L13
	tbz	x0, 0, .L15
	mov	x1, 2
	b	.L11
	.p2align 2,,3
.L12:
	udiv	x2, x0, x1
	msub	x2, x2, x1, x0
	cbz	x2, .L15
.L11:
	add	x1, x1, 1
	cmp	x0, x1
	bne	.L12
.L13:
	mov	w0, 1
	ret
	.p2align 2,,3
.L15:
	mov	w0, 0
	ret
	.cfi_endproc
.LFE1599:
	.size	_Z8is_primem, .-_Z8is_primem
	.section	.text.startup,"ax",@progbits
	.align	2
	.p2align 4,,11
	.type	_GLOBAL__sub_I__Z3addii, %function
_GLOBAL__sub_I__Z3addii:
.LFB2092:
	.cfi_startproc
	stp	x29, x30, [sp, -32]!
	.cfi_def_cfa_offset 32
	.cfi_offset 29, -32
	.cfi_offset 30, -24
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -16
	adrp	x19, .LANCHOR0
	add	x19, x19, :lo12:.LANCHOR0
	mov	x0, x19
	bl	_ZNSt8ios_base4InitC1Ev
	mov	x1, x19
	adrp	x0, :got:_ZNSt8ios_base4InitD1Ev
	ldr	x19, [sp, 16]
	adrp	x2, __dso_handle
	ldp	x29, x30, [sp], 32
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	add	x2, x2, :lo12:__dso_handle
	ldr	x0, [x0, #:got_lo12:_ZNSt8ios_base4InitD1Ev]
	b	__cxa_atexit
	.cfi_endproc
.LFE2092:
	.size	_GLOBAL__sub_I__Z3addii, .-_GLOBAL__sub_I__Z3addii
	.section	.init_array,"aw"
	.align	3
	.xword	_GLOBAL__sub_I__Z3addii
	.bss
	.align	3
	.set	.LANCHOR0,. + 0
	.type	_ZStL8__ioinit, %object
	.size	_ZStL8__ioinit, 1
_ZStL8__ioinit:
	.zero	1
	.hidden	__dso_handle
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
