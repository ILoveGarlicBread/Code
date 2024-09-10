  .data
    array: .word 0, 1, 2, 3, 4
    result: .asciiz "Result: "  
  .text
  .globl main


main:
  li $t0, 0
  li $t1, 0 
  
  loop:
    lw $t2, array ($t1)
    add $t0, $t0, $t2
    addi $t1, $t1, 4
    blt $t1, 20, loop
     
  li $v0, 4
  la $a0, result
  syscall

  li $v0, 1
  move $a0, $t0
  syscall

  li $v0, 10
  syscall
