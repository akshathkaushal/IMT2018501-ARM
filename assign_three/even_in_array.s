	 AREA     even, CODE, READONLY
     EXPORT __main
     IMPORT printMsg
     ENTRY 
__main  FUNCTION
		LDR R0,=0x0A;      size of array is 10
		LDR R12,=0x20000000;
		LDR R11,=0x0;     
		LDR R1,=0x5; Array elementts
		LDR R2,=0x2;
		LDR R3,=0x8;
		LDR R4,=0xF;       
		LDR R5,=0x9;
		LDR R6,=0x6;
		LDR R7,=0xD;
		LDR R8,=0x7;
		LDR R9,=0x3;
		LDR R10,=0xA;
		STR R1,[R12,0x00]; Storing register values into memory addresses.
		STR R2,[R12 ,0x04];
		STR R3,[R12,0x08];
		STR R4,[R12 ,0x0C];
		STR R5,[R12,0x10];
		STR R6,[R12 ,0x14];
		STR R7,[R12,0x18];
		STR R8,[R12 ,0x1C];
		STR R9,[R12,0x20];
		STR R10,[R12 ,0x24];
		
Loop    LDR R5,[R12]
        
		SUB R0,#0x01;
		ADD R12,#0x04;
        TST R5,0x00000001
		IT EQ
		ADDEQ R11,#0x1;
		CMP R0,#00
		BNE Loop
		MOV R0,R11;
		BL printMsg;    
									
		
stop    B stop ; stop program
	ENDFUNC
	END 
