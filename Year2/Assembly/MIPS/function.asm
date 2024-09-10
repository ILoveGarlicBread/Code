.data
  message: .asciiz "Hello"




.text

main:
  jal displayMessage

  
  li $v0, 10
  syscall




  displayMessage:
    li $v0, 4
    la $a0, message
    syscall

  jr $ra




