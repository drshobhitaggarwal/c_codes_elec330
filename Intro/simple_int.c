#include <stdio.h>

int main() {
    float principal, rate, time, simple_interest;

    // Get input from the user
    principal=2000;
	rate=3;
	time=1;

    // Calculate simple interest
    simple_interest = (principal * rate * time) / 100;

    // Display the result
    printf("Simple Interest = %.2f\n", simple_interest);

    return 0;
}

