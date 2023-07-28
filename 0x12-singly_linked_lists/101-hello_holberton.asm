section .data
    hello db 'Hello, Holberton', 0

section .text
    extern printf
    global _start_asm

_start_asm:
    ; Load the address of the hello string into a register
    mov rdi, hello
    
    ; Call the printf function
    mov rax, 0x2000004 ; System call number for write
    mov rsi, rdi      ; Address of the string
    mov rdx, 16       ; Length of the string
    syscall
    
    ; Set the exit system call number (60) into a register
    mov rax, 0x2000001 ; System call number for exit
    xor rdi, rdi      ; Exit status (0)
    syscall

section .data
    format db '%s', 0

section .text
global main
main:
    ; Dummy main function
    xor eax, eax
    ret

