	.arch armv8-a
	.file	"loop.cc"
	.text
	.align	2
	.p2align 4,,11
	.global	_Z3sumi
	.type	_Z3sumi, %function
_Z3sumi:
.LFB0:
	.cfi_startproc
	cmp	w0, 0
	ble	.L4
	add	w2, w0, 1 // i = 1 | w2 = n
	mov	w1, 1 // lines 13-15 everything before i <= n
	mov	w0, 0 // sum = 0
	.p2align 3,,7
.L3:
	add	w0, w0, w1 // sum = sum + i
	add	w1, w1, 1 // i = i+1 = 2
	cmp	w1, w2 // is w1 = w2?
	bne	.L3 // if not, go back and do it again
	ret
	.p2align 2,,3
.L4:
	mov	w0, 0
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3sumi, .-_Z3sumi
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
