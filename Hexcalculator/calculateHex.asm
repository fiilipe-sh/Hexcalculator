section .data

 global ResultRdxResistor
 ResultRdxResistor dq 0

 global ResultRdxResistorSession2
 ResultRdxResistorSession2 dq 0

 global ResultRaxResistor
 ResultRaxResistor dq 0


section .text
global ConvertHexToDec

 ConvertHexToDec:
 mov rax,rdi
 mov rdx,0
 mov rcx,16
 div rcx

 cmp rdx,0
 jz returnlabel

 mov [ResultRdxResistor], rdx

 loopVerification:
 div rcx
 mov [ResultRdxResistorSession2],rdx
 mov [ResultRaxResistor],rax

 cmp rcx,16
 jl returnlabel

 jmp loopVerification

 returnlabel:
 ret
