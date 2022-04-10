  // implement function:
  // uint64_t f(uint64_t a[], uint32_t len);
// return sum(a[i] cubed ) - sum(a[i]) ** 3
_Z1fPmj:

// implement function:
// void add1(uint64_t a[], uint32_t len);
// for each element a[i] read it in, add 1, write it back

  // complete code so counting down from x0 works
  // this loop should run x0 times
countdown:
1:
  // this line should be execute x0 times
  subs x0, x0, #1
  bne 1b

  //compete code so counting down from x0 works
  //this loop should run x0 times

countdownby2:
1:
  // this line should be executed x0 times
  sub x0, #2 // can also be subs
  cmp x0, 0
  bne 1b

  //compete code so counting down from x0 works
  //this loop should run x0 times

countdown3:
1:
  // this line should be executed x0 times
  sub x0, x0, #1
  cmp x0, #1
  bge 1b

countdownby2:
1:
  // this line should be executed x0/2 times
  ___ x0, x0, #2
  bne 1b

  //x0 = array of uint64_t
  //x1 = length
arraylookup1:
  mov x3, #0 // sum=0
1:
  ldr x3, [x0], #8 //load a[i]
  add x2, x2, x3 // sum = sum+a[i]
  subs x1, #1 //
  bne 1b
  mov x0, x2
  ret

  //x0 = array of uint64_t
  //x1 = length
arraylookup1b:
  mov x2, #0 // sum=0
  mov x4, #0 // for (int i = 0; i < x1; i++)
1:
  ldr x3, [x0, x4 lsl #3] // <- 0 lsl 3 = 0, 1 lsl 3 = 8
  add x2, x2, x3 // sum = sum+a[i]
  subs x4, x4, #1 // add
  cmp x4, x1
  blt 1b
  mov x0, x2
  ret

  //x0 = array of uint32_t
  //x1 = length
arraylookup2:
  
  // ...similar but...
  ldr w3, [x0], #4

  ldr w3, [x0, x4 lsl #2]

  //x0 = array of uint8_t
  //x1 = length
arraylookup3:


  // for (int i = 0; i < n; i++) x[i]

  //going backwards through array x[n]

  // for (int i = n-1; i >= 0; i--) x[i]
  // for (uint32_t i = n-1; i>=0; i--) x[i]





