section .data
  result db 0 
  newline db 10

section .text
  global _start

_start:
  mov eax, 1
  add eax, 2
  mov [result], eax

  mov eax, 4
  mov ebx, 1 
  mov ecx, result 
  mov edx, 4 
  int 0x80

  mov eax, 1
  xor ebx, ebx
  int 0x80
