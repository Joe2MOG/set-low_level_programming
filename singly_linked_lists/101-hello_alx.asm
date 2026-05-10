; 64-bit NASM assembly: prints "Hello, ALX\n" using printf
; Compile: nasm -f elf64 101-hello_alx.asm && gcc -no-pie -std=gnu89 101-hello_alx.o -o hello

section .data
    msg db "Hello, ALX", 10, 0   ; 10 = newline, 0 = null terminator

section .text
    global main
    extern printf

main:
    push    rbp                 ; prologue (optional but nice)
    mov     rdi, msg            ; first argument: pointer to the string
    xor     eax, eax            ; 0 indicates no floating-point arguments
    call    printf              ; call printf(msg)
    pop     rbp                 ; epilogue
    xor     eax, eax            ; return 0
    ret
