; 64-bit NASM assembly: prints "Hello, Holberton\n" using printf
; Compile: nasm -f elf64 101-hello_alx.asm && gcc -no-pie -std=gnu89 101-hello_alx.o -o hello

section .data
    msg db "Hello, Holberton", 10, 0   ; 10 = newline, 0 = null terminator

section .text
    global main
    extern printf

main:
    push    rbp                 ; set up stack frame (optional but clean)
    mov     rdi, msg            ; first argument: pointer to the string
    xor     eax, eax            ; number of floating-point arguments = 0
    call    printf              ; call printf(msg)
    pop     rbp                 ; restore stack frame
    xor     eax, eax            ; return 0
    ret
