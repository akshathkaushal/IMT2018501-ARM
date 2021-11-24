     AREA     largestarr, CODE, READONLY
     EXPORT __main
     IMPORT printMsg
     ENTRY 
__main  FUNCTION
		LDR R0,=0x0A;      
		LDR R11,=0x20000000;
		LDR R12,=0x0;     This register is being used to store maximum variable 
		LDR R1,=0x10;       Array elementts
		LDR R2,=0x9;
		LDR R3,=0x8;
		LDR R4,=0x7;
		LDR R5,=0x6;
		LDR R6,=0x5;
		LDR R7,=0x4;
		LDR R8,=0x3;
		LDR R9,=0x2;
		LDR R10,=0x1; 
		STR R1,[R11,0x00];  Storing register values into memory addresses.
		STR R2,[R11 ,0x04];
		STR R3,[R11,0x08];
		STR R4,[R11 ,0x0C];
		STR R5,[R11,0x10];
		STR R6,[R11 ,0x14];
		STR R7,[R11,0x18];
		STR R8,[R11 ,0x1C];
		STR R9,[R11,0x20];
		STR R10,[R11 ,0x24];
		
Loop    LDR R1,[R11]
        
		SUB R0,#0x01;
		ADD R11,#0x04;
        CMP R1,R12
		IT GT
		MOVGT R12,R1;
		CMP R0,#00
		BNE Loop
		MOV R0,R12;
		BL printMsg;   
									
		
stop    B stop ; stop program
	ENDFUNC
	END
