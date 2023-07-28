section .data
    hello db "Hello, Holberton", 0
    format db "%s", 0

section .text
    extern printf

    global main
    main:
        push rbp
        mov rbp, rsp

        sub rsp, 8     ; Allocate space for two arguments

        mov rdi, format
        mov rsi, hello
        xor eax, eax   ; Clear eax register before calling printf
        call printf

        mov eax, 0
        leave
        ret

