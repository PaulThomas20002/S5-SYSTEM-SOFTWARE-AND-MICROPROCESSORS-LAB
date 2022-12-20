ASSUME CS: CODE, DS:DATA
DATA SEGMENT
           OPR1 DW 1234H
           OPR2 DW 5678H
            RESULT DW ?
DATA ENDS

CODE SEGMENT

START: MOV AX, DATA
            MOV DS,AX
            MOV AX,OPR1
            MOV BX,OPR2
            ADD AX,BX
            MOV RESULT,AX
            MOV AH,4CH
            INT 21H
CODE ENDS
END START
