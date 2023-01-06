section .data
  msg db "", 10
 len: equ $ - msg
section .text
  global _start

_start:
  mov rax, 00
  mov rdi, 0
  mov rsi, msg
  mov rdx, len
  syscall
  
  mov rax, 01
  mov rdi, 01
  mov rsi, msg
  mov rdx, len
  syscall

  mov rax, 60
  mov rdi, 0
  syscall
