.data



.text
main:



fact: add $a0, $a0, -1
      jal fact 
      mul $v0, $v0, $a0
      jr $ra 

