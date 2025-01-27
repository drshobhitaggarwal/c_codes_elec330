#include <stdio.h>
#include <string.h> // For string functions like strlen, strcpy, etc.

int main() {
    // Method 1: Initializing a character array (string) directly
    char str1[] = "Hello"; // Compiler automatically adds null terminator '\0'
    // str1 is equivalent to {'H', 'e', 'l', 'l', 'o', '\0'}

    // Method 2: Initializing with individual characters
    char str2[6] = {'W', 'o', 'r', 'l', 'd', '\0'}; // Explicit null terminator is crucial!

    // Method 3: Declaring and then assigning (using strcpy is safer)
    char str3[20]; // Allocate enough space
    strcpy(str3, "C Programming"); // Copies the string into str3, including the '\0'

    // Printing strings
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    // Accessing individual characters
    printf("First character of str1: %c\n", str1[0]); // Output: H
    printf("Third character of str2: %c\n", str2[2]); // Output: r

    // String length (excluding the null terminator)
    printf("Length of str1: %zu\n", strlen(str1)); // Use %zu for size_t

    // Modifying a string (be careful about buffer overflows)
    str1[0] = 'J'; // Change the first character of str1
    printf("Modified str1: %s\n", str1); // Output: Jello

    // Example of reading a string from the user (using fgets is safer)
    char str4[50];
    printf("Enter a string: ");
    fgets(str4, sizeof(str4), stdin); // Reads input including spaces, prevents buffer overflows
    // fgets adds a newline character '\n' at the end if the input string fits in the buffer.
    // You might want to remove the newline:
    str4[strcspn(str4, "\n")] = 0; // Removes trailing newline if present.
    printf("You entered: %s\n", str4);


    // Demonstrating the null terminator
    char str5[10] = "Short";
    printf("str5 in memory (as characters): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", str5[i]); // Print the ASCII values
    }
    printf("\n");
    printf("str5: %s\n", str5);

    char str6[5] = "LongerString"; // Buffer overflow! This is dangerous!
    printf("str6: %s\n", str6); // Undefined behavior, likely crash or corrupted data

    return 0;
}

