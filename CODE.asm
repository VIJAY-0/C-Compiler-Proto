section .data
a dq 0
b dq 2
temp0 dq 4
temp1 dq 6
temp2 dq 8
section .text
global _start 
 _start: 

MOV rdi, 12
ADD rdi, 34
MOV [temp0], rdi


MOV rdi, [a]
ADD rdi, 1000
MOV [temp1], rdi


MOV rdi, [a]
ADD rdi, 1234
MOV [temp2], rdi


MOV rax, 60 
syscall

