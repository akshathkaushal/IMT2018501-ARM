#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	int arr[20];
	printf("Enter 20 numbers\n");
	int i=0;
	for(i=0;i<20;i++){
		scanf("%d", &arr[i]);
	}
	i=0;
	int count=0;
	for(i=0;i<20;i++){
		if(arr[i]%2==0) count++;
	}
	printf("Total even numbers are: %d\n", count);


	return 0;
}
