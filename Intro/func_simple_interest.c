#include <stdio.h>

float _simple_interest(float prin, float rate, float time){
	float si=0;
	si=(prin*rate*time)/100;
	return si;
}

int main() {
    float principal, rate, time, simple_interest;

    principal=2000;
	rate=3;
	time=1;

    // Calculate simple interest
    simple_interest = _simple_interest(principal,rate,time);

    // Display the result
    printf("Simple Interest = %.2f\n", simple_interest);

    return 0;
}