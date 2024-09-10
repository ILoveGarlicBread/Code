#Check if a number input by user is odd or even

.data
  new_line: .asciiz "\n"
  prompt_a: .asciiz "Input a: "
  isOdd: .asciiz "This number is odd."
  isEven: .asciiz "This number is even."


.text
.globl main

main:
  li $v0, 4
  la $a0, prompt_a 
  syscall

  li $v0, 5
  syscall
  move $s0, $v0

  # In binary, odd numbers end with 1, even numbers end with 0
  # e.g.: 2 = 0010
  #       3 = 0011
  #       6 = 0110
  #       9 = 1001
  # Use bitwise AND operation with 1, return 1 if odd and 0 if even
  andi $t0, $s0, 1
  # check 
  beq $t0, $zero, EVEN
    j ODD


  ODD:
    li $v0, 4
    la $a0, isOdd
    syscall
    j EXIT

  EVEN:
    li $v0, 4
    la $a0, isEven
    syscall
    j EXIT

  EXIT:
    li $v0, 4
    la $a0, new_line
    syscall

    li $v0, 10
    syscall





