    .data
matrix:
    .word 1, 2, 3, 4      # Row 0: 1 2 3 4
    .word 5, 6, 7, 8      # Row 1: 5 6 7 8
    .word 9, 10, 11, 12   # Row 2: 9 10 11 12

    .text
    .globl main

main:
    # Calculate the base address of the matrix
    la $t0, matrix

    # Accessing matrix element at row 1, column 2 (indexing starts from 0)
    li $t1, 1      # Row
    li $t2, 2      # Column
    li $t3, 4      # Number of columns in the matrix

    # Calculate the offset: row * number_of_columns + column
    mul $t4, $t1, $t3    # $t4 = row * number_of_columns
    add $t4, $t4, $t2    # $t4 = row * number_of_columns + column

    # Calculate the memory address of the element: base_address + offset
    add $t5, $t0, $t4    # $t5 = base_address + offset

    lw $t6, 0($t5)    # Load the value at the calculated address into $t6

    # Now $t6 contains the value of matrix[1][2]
    
    # Exit the program
    li $v0, 10      # syscall code 10: exit
    syscall
