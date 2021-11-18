     AREA  largest, CODE, READONLY
     EXPORT __main
     IMPORT printMsg
	 
     ENTRY 
__main  FUNCTION
	
		MOV R0,#0x20000000;  
		LDR R1,=0x8;
		LDR R2,=0x12;
		LDR R3,=0x37;
		STR R1,[R0,0x00]; Storing register values into memory addresses.
		STR R2,[R0 ,0x04];
		STR R3,[R0,0x08];
		LDR R4,[R0,#0x00];    
		LDR R5,[R0,#0x04];
		LDR R6,[R0,#0x08];
		cmp R4,R5;            Comparison of first 2 numbers
		ITE LT
		MOVLT R7,R5;
		MOVGE R7,R4;
		cmp R6,R7;            Comparing the greatest of first two numbers with third number.
		ITE LT
		MOVLT R0,R7;
		MOVGE R0,R6;
		BL printMsg;           Printing the final largest number.
				
stop B stop ;
    ENDFUNC
	END
