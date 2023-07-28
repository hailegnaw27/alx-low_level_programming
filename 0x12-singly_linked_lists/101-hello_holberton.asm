#!/bin/bash
section .data
    hello db 'Hello, Holberton', 0

section .text
    global _start

_start:
    ; Write the string to stdout
    mov rax, 1                  ; System call number for write
    mov rdi, 1                  ; File descriptor for stdout
    mov rsi, hello              ; Address of the string
    mov rdx, 17                 ; Length of the string
    syscall

    ; Exit the program
    mov eax, 60                 ; System call number for exit
    xor edi, edi                ; Exit status 0
    syscall

