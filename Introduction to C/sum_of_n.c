#include <stdio.h>

int main() {
    int n, sum= 0;

    printf("Enter the number of integers you want to add: ");
    scanf("%d", &n);
	
	for (int i = 0; i <=n; i++) {
        sum += i; // Add the current number to the sum
    }

	
    printf("The sum of the %d integers is: %d\n", n, sum);

    return 0; // Indicate successful execution
}


