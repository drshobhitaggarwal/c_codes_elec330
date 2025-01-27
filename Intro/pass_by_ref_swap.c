#include <stdio.h>

void swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}



void swap2(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void main(){
	int m, n;
	m = 15;
	n = 20;
	swap(m, n);
	printf("\n Swap1 Output\n");
	printf("x: %d \n y: %d", m,n);
	
	swap2(&m, &n);
	printf("\n Swap2 Output\n");
	printf("x: %d \n y: %d", m,n);
}
	
