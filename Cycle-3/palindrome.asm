ASSUME CS:CODE,DS:DATA
DATA SEGMENT
	MYSTRING DB 'MALAYALAM$'
	STRING1 DB 'PALINDROME$'
	STRING2 DB 'NOT PALINDROME$'
DATA ENDS
CODE SEGMENT
	START: MOV AX,DATA
		MOV DS,AX
		LEA DI,MYSTRING
		MOV SI,DI
	BACK: MOV AL,[DI]
		CMP AL,'$'
		JZ BACK1
		INC DI
		JMP BACK
	BACK1: DEC DI
		CMP SI,DI
		MOV AL, [SI]
		CMP AL,[DI]
		JNZ PRINT2
		INC SI
		JMP BACK1
	PRINT1: LEA DX, STRING1
		JMP L2
	PRINT2: LEA DX,STRING2
	    L2: MOV AH,09H
		INT 21H
		MOV AH,4CH
		INT 21H
CODE ENDS
END START
