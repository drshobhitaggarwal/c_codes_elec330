#include <stdio.h>

int main() {
    int a = 5, b = 3;

    // AND operator (&&)
    if (a > 0 && b > 0) {
        printf("Both 'a' and 'b' are greater than 0.\n");
    } else {
        printf("At least one of 'a' or 'b' is not greater than 0.\n");
    }

    // OR operator (||)
    if (a == 5 || b == 5) {
        printf("Either 'a' or 'b' is equal to 5.\n");
    } else {
        printf("Neither 'a' nor 'b' is equal to 5.\n");
    }
	
    return 0;
}