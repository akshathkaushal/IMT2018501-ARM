#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int arr[], int left, int mid, int right){

	int leftSz = mid-left+1;
	int rightSz = right-mid;

	int leftArr[leftSz], rightArr[rightSz];

	int i;
	for(i=0;i<leftSz;i++){
		leftArr[i]=arr[left+i];
	}
	for(i=0;i<rightSz;i++){
		rightArr[i]=arr[mid+1+i];
	}
	
	i=0;
	int j=0, k=left;
	while(i<leftSz && j<rightSz){
		if(leftArr[i]<rightArr[j]){
			arr[k] = leftArr[i];
			i++;
		}
		else {
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while(i<leftSz){
		arr[k] = leftArr[i];
		i++;
		k++;
	}
	while(j<rightSz){
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r){

	if(l<r){
		int mid = l+(r-l)/2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}

}

int main() {

	int arr[20];
	printf("Enter 20 numbers\n");
	int i=0;
	for(i=0;i<20;i++){
		scanf("%d", &arr[i]);
	}

	mergeSort(arr, 0, 19);
	i=0;
	printf("Sorted array is:\n");
	for(i=0;i<20;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
//20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
