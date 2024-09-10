#Input a and b then solve a*x + b = 0

.data
  new_line: .asciiz "\n"
  IntergerA: .asciiz "Input for a: "
  IntergerB: .asciiz "Input for b: "
  equation: .asciiz "a*x + b = 0"
  result: .asciiz "x = : "
.text

.globl main


main: 
  li $v0, 4
  la $a0, IntergerA
  syscall

  li $v0, 5
  syscall 
  move $s0, $v0

  li $v0, 4
  la $a0, IntergerB
  syscall

  li $v0, 5
  syscall
  move $s1, $v0

  li $t0, -1 
  mul $s1, $t0, $s1
  div $s1, $s0
  mflo $t3
  
  li $v0 ,4
  la $a0, equation
  syscall

  li $v0, 4
  la $a0, new_line
  syscall
  
  li $v0, 4
  la $a0, result
  syscall

  li $v0, 1
  move $a0, $t3
  syscall

  li $v0, 4
  la $a0, new_line
  syscall

  li $v0, 10
  syscall



