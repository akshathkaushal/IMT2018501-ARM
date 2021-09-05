#include<stdio.h>
#include<stdlib.h>

int* queue;
int queue_size;
int queue_ptr;
int remove_ptr=0;

void createQueue(int size_){
	queue = (int*)malloc(size_*sizeof(int));
	queue_size = size_;
	queue_ptr = 0;
}



void add_to_queue(int val){
	if(queue_ptr == queue_size) {
		printf("Error: Queue is full!\n");
	}
	else {
		queue[queue_ptr] = val;
		queue_ptr++;
	}
}

int remove_from_queue(){
	if(queue_ptr == 0){
		printf("Error: Queue is empty!\n");
		return -1;
	}
	else {
		int ret = queue[remove_ptr];
		queue[remove_ptr] = NULL;
		remove_ptr++;
		return remove_ptr;
	}
}

void print(){
	int i=0;
	for(i=remove_ptr;i<queue_ptr;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}


int main(int argc, char* argv[]){

	int qsz = atoi(argv[1]);
	createQueue(qsz);
	add_to_queue(1);
	add_to_queue(2);
	add_to_queue(3);
	add_to_queue(4);
	add_to_queue(5);
	add_to_queue(6);
	add_to_queue(7);
	add_to_queue(8);
	printf("Element removed: %d\n",remove_from_queue());
	print();
	printf("Element removed: %d\n",remove_from_queue());
	printf("Element removed: %d\n",remove_from_queue());
	print();
	add_to_queue(9);
	add_to_queue(10);
	add_to_queue(11);
	print();

	return 0;
}