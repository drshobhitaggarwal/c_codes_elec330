#include <stdio.h>
#include <limits.h> // For limits of integer data types

int main() {
    // Integer data types
    char character = 'A'; 
    short int short_int = -32768; 
    int integer = 2147483647; 
    long int long_int = 9223372036854775807L; // L suffix for long int

    // Floating-point data types
    float floating_point = 3.14159f; // f suffix for float
    double double_precision = 2.718281828459045; 
    long double long_double = 1.2345678901234567890123456789012345L; // L suffix for long double

    // Void data type (no value)
    void *void_pointer; 

    // Print data types and their values
    printf("Character: %c\n", character);
    printf("Short Int: %hd\n", short_int);
    printf("Integer: %d\n", integer);
    printf("Long Int: %ld\n", long_int);

    printf("Float: %f\n", floating_point);
    printf("Double: %lf\n", double_precision);
    printf("Long Double: %Lf\n", long_double);

    // Print limits of integer data types
    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("LONG_MIN: %ld\n", LONG_MIN);
    printf("LONG_MAX: %ld\n", LONG_MAX);

    return 0;
}