    .data
prompt_a:   .asciiz "Enter value for a: "
prompt_b:   .asciiz "Enter value for b: "
prompt_c:   .asciiz "Enter value for c: "
result:     .asciiz "Result of (a + b - c) is: "

    .text
    .globl main

main:
    # Prompt for input a
    li $v0, 4
    la $a0, prompt_a
    syscall

    # Read integer input for a
    li $v0, 5
    syscall
    move $s0, $v0  # Save a in $s0

    # Prompt for input b
    li $v0, 4
    la $a0, prompt_b
    syscall

    # Read integer input for b
    li $v0, 5
    syscall
    move $s1, $v0  # Save b in $s1

    # Prompt for input c
    li $v0, 4
    la $a0, prompt_c
    syscall

    # Read integer input for c
    li $v0, 5
    syscall
    move $s2, $v0  # Save c in $s2

    # Compute (a + b - c)
    add $t0, $s0, $s1   # $t0 = a + b
    sub $t1, $t0, $s2   # $t1 = (a + b) - c

    # Display result
    li $v0, 4
    la $a0, result
    syscall

    # Display the calculated result
    li $v0, 1
    move $a0, $t1
    syscall

    # Exit the program
    li $v0, 10
    syscall
