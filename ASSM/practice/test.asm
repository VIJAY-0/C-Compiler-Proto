section .text
global _start

_start:
    ; Set up the 128-bit dividend (rdx:rdi:rax)
    mov rax, 48           ; Low-order 64 bits of dividend
    ; mov rdi, 0           ; Middle 64 bits of dividend
    ; mov rdx, 100         ; High-order 64 bits of dividend (change as needed)

    ; Divide the 128-bit value by 24
    mov r8, 24
    ; mov r9, 0             ; Clear the upper 64 bits of the divisor
    ; mov r10, 0            ; Clear any potential garbage value in r10
    div r8

    ; Result is now in rax (quotient) and rdx (remainder)

    ; Your further instructions go here...

    ; Exit the program
    mov rax, 60           ; System call number for exit
    xor rdi, rdi          ; Exit status 0
    syscall               ; Invoke the system call
