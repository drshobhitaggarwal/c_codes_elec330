#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* Converts a string with numbers into integers*/ 
// args str: pointer to the string
// returns integer value
// Make sure to handle the case for strings consisting of data other than integer value

int string_to_int(const char* str) {
    int result = 0;
    int sign = 1;

    // Handle optional '-' sign
    if (*str == '-') {
        sign = -1;
        str++;
    }

    // Convert each character to its integer value
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
        } else {
            return 0; // Return 0 or handle the error appropriately
        }
        str++;
    }

    return result * sign;
}