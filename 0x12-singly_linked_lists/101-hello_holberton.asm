section .data
    hello db "Hello, Holberton", 0

section .text
    extern printf

global main
main:
    sub rsp, 8

    mov rdi, hello
    xor eax, eax
    call printf

    add rsp, 8

    mov eax, 0x60
    xor edi, edi
    syscall

