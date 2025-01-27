#include <stdio.h>

int main() {
    int n;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            printf("BuzzFish\n");
        } else if (i % 3 == 0) {
            printf("Buzz\n");
        } else if (i % 5 == 0) {
            printf("Fish\n");
        } else {
            printf("%d\n", i);
        }
    }

    return 0;
}