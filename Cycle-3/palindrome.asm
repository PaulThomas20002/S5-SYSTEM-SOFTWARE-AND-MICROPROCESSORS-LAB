ASSUME CS:CODE,DS:DATA
DATA SEGMENT
        mystring db 'Paul thomas$'
        string1 db 'palindrome$'
        string2 db 'not palindrome$'
DATA ENDS
CODE SEGMENT
START:
        MOV AX,DATA
        MOV DS,AX
        LEA DI,mystring
        MOV SI,DI
    BACK:MOV AL,[DI]
        CMP AL,'$'
        JZ SCAN
        INC DI
        JMP BACK
 SCAN:  DEC DI
         CMP SI,DI
        JNC OUT1
        MOV AL,[SI]
        CMP AL,[DI]
        JNZ OUT2
        INC SI
        JMP SCAN
   OUT1:LEA DX,string1
        JMP L2
   OUT2:LEA DX, string2
   L2: MOV AH,09H
        INT 21H
        MOV AH,4CH
        INT 21H
 CODE ENDS
 END START
