#include <stdio.h>

#define CLASS_SIZE 5

void main(){
	
	int total=0;
	int avg=0;
	int grade[CLASS_SIZE];
	grade[0]=96;
	grade[1]=95;
	grade[2]=92;
	grade[3]=91;
	grade[4]=98;
	grade[5]=90;
	
	for(int i=0; i<=CLASS_SIZE ; i++){
		printf("Grade for student %d is %d\n", i, grade[i]);
	}
	
	for(int i=0; i<=CLASS_SIZE ; i++){
		total+=grade[i];		
	}
	avg=total/(CLASS_SIZE+1);
	printf("Class Average = %d\n", avg);
}

