section .data
    num1: dd 12
    num2: dd 55
    lf: db " ", 10, 0
    res: dd "    ", 10, 0
    len_res equ $ - res

section .text
  global _start

_start:
.sum:
    mov rax, [num1]
    add rax, [num2]
    mov [res], rax   

.show_result:
    mov rax, 1
    mov rdi, 1
    mov rsi, res
    mov rdx, len_res
    syscall

.showLF:
    mov rax, 1
    mov rdi, 1
    mov rsi, lf
    mov rdx, 2
    syscall

.exit:
    xor edi, edi
    mov rax, 60
    syscall
