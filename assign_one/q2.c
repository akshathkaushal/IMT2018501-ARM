#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	int arr[15];
	printf("Enter 15 numbers\n");
	int i=0;
	for(i=0;i<15;i++){
		scanf("%d", &arr[i]);
	}
	i=0;
	int maxEl=0;
	for(i=0;i<15;i++){
		if(arr[i]>maxEl) maxEl = arr[i];
	}
	printf("Largest number is: %d\n", maxEl);

	return 0;
}
