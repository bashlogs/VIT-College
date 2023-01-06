section .data
  msg db 0, 10

section .text
  global _start

_start:
  
  mov rax, 7
  call _printRAXDigit

_printRAXDigit
  mov rax, 48
  mov [digit], al
  mov ax, 1
  mov rdi, 1
  mov rsi, digit
  mov rdx, 2
  syscall
  ret
