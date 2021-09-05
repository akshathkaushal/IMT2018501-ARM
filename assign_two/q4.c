#include<stdio.h>
#include<stdlib.h>


int* stack;
int stack_ptr;
int stack_size;


void createStack(int size_) {
	stack = (int*)malloc(size_*sizeof(int));
	stack_ptr = -1; // stack type -1
	stack_size = size_;
}


void print() {
	int i=0;
	printf("Printing the stack...\n");
	for(i=0;i<=stack_ptr;i++){
		printf("%d ", stack[i]);
	}
	printf("\n");
}

void push(int val) {

	if(stack_ptr == stack_size){
		printf("Error: Stack is full!\n");
	}
	else { // defines empty or full
		stack_ptr = stack_ptr + 1;
		stack[stack_ptr] = val;
	}
}

int pop() {

	if(stack_ptr == -1){
		printf("Error: Stack is empty!\n");
		return -1;
	}	
	else {
		stack_ptr = stack_ptr - 1;
		int ret = stack[stack_ptr+1];
		stack[stack_ptr+1] = NULL;
		return ret;
	}
}



int main(int argc, char* argv[]){
	
	int ssz = atoi(argv[1]);
	createStack(ssz);

	push(1); // 0
	push(2); // 1
	push(3); // 2
	push(4); // 3
	push(5); // 4
	printf("Element removed: %d\n",pop()); // 3
	print();


	return 0;
}