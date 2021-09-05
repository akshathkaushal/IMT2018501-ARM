#include<stdio.h>
#include<stdlib.h>

int* queue;
int queue_size;
int queue_ptr;
int remove_ptr;

void createQueue(int size_){
	queue = (int*)malloc(size_*sizeof(int));
	queue_size = size_;
	queue_ptr = -1;
	remove_ptr = -1;
}

void add_to_queue(int val){
	if(remove_ptr == 0 && queue_ptr == queue_size-1 || queue_ptr == (remove_ptr-1)%queue_size){
		printf("Error: Queue is full!\n");
	}
	else {
		if(remove_ptr == -1) {
			remove_ptr=0;
			queue_ptr=0;
			queue[queue_ptr] = val;
		}
		else if(queue_ptr==queue_size-1 && remove_ptr!=0){
			queue_ptr=0;
			queue[queue_ptr]=val;
		}
		else {
			queue_ptr++;
			queue[queue_ptr]=val;
		}
	}
}

int remove_from_queue(){
	if(remove_ptr==-1){
		printf("Error: Queue is empty!\n");
		return -1;
	}
	int ret = queue[remove_ptr];
	queue[remove_ptr]=NULL;
	if(queue_ptr==remove_ptr){
		queue_ptr=-1;
		remove_ptr=-1;
	}
	else if(remove_ptr==queue_size){
		remove_ptr=0;
	}
	else {
		remove_ptr++;
	}
	return ret;
}

void print(){
	if(remove_ptr==-1) {
		printf("Queue is Empty!");
	}
	if(queue_ptr >= remove_ptr){
		int i;
		for(i=remove_ptr;i<=queue_ptr;i++){
			printf("%d ", queue[i]);
		}
	}
	else {
		for (int i = remove_ptr; i < queue_size; i++)
            printf("%d ", queue[i]);
 
        for (int i = 0; i <= queue_ptr; i++)
            printf("%d ", queue[i]);
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
	add_to_queue(12);
	print();

	return 0;
}