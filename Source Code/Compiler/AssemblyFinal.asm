section .data

cw dw 057fH
integer_1 dd 1
REG_INT  dd 0
REG_REAL dq 0.0
format_read_int db "%d", 0
format_read_char db "%c", 0
format_read_real db "%lf", 0
address_var_1 dd 0
msg_1 db "%c", 0
msg_2 db "%c", 0
array_1 TIMES 26 dd 0
address_var_2 dd 0

section .text

extern _printf
extern _scanf
global _main
_main:
    fldcw [cw]
    call _source_main
    ret

; ----------------------- ;

_showString_intArr_int:
    push ebp
    mov  ebp, esp
    push 0
    mov  eax, 0
    mov  dword [ebp - 4], eax
    While1:
    mov  eax, [ebp - 4]
    cmp  eax, [ebp + 12]
    mov  eax, 1
    jl   $+7
    mov  eax, 0
    mov  dword [REG_INT], eax
    mov  ecx, [REG_INT]
    cmp  ecx, 0
    je   EndWhile1
    mov  eax, [ebp - 4]
    imul eax, 4
    add  eax, [ebp + 8]
    mov  dword [address_var_1], eax
    mov  eax, [address_var_1]
    mov  eax, [eax]
    mov  dword [REG_INT], eax
    push dword [REG_INT]
    push msg_1
    call _printf
    add  esp, 8
    mov  eax, [ebp - 4]
    mov  dword [REG_INT], eax
    inc  eax
    mov  dword [ebp - 4], eax
    jmp  While1
    EndWhile1:
    push 10
    push msg_2
    call _printf
    add  esp, 8
    mov  eax, 0
    mov  esp, ebp
    pop  ebp
    ret  8

; ----------------------- ;

_source_main:
    push ebp
    mov  ebp, esp
    push array_1
    push 0
    push 0
    mov  eax, 0
    mov  dword [ebp - 8], eax
    While2:
    mov  eax, [ebp - 8]
    cmp  eax, 26
    mov  eax, 1
    jl   $+7
    mov  eax, 0
    mov  dword [REG_INT], eax
    mov  ecx, [REG_INT]
    cmp  ecx, 0
    je   EndWhile2
    mov  eax, [ebp - 8]
    imul eax, 4
    add  eax, [ebp - 4]
    mov  dword [address_var_2], eax
    mov  eax, 97
    add  eax, [ebp - 8]
    mov  dword [REG_INT], eax
    mov  ecx, [address_var_2]
    mov  eax, [REG_INT]
    mov  dword [ecx], eax
    mov  eax, [ebp - 8]
    mov  dword [REG_INT], eax
    inc  eax
    mov  dword [ebp - 8], eax
    jmp  While2
    EndWhile2:
    push 26
    push dword [ebp - 4]
    call _showString_intArr_int
    mov  dword [REG_INT], eax
    mov  eax, [REG_INT]
    mov  dword [ebp - 12], eax
    mov  eax, 0
    mov  esp, ebp
    pop  ebp
    ret  0

; ----------------------- ;

