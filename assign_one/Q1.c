#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	int a;
	int b;
	int c;

	printf("Enter 3 numbers: \n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	printf("Largest number is: ");

	if(a>b){
		if(c > a) printf("%d\n", c);
		else printf("%d\n", a);
	}
	else {
		if(c > b) printf("%d\n", c);
		else printf("%d\n", b);
	}

	return 0;
}