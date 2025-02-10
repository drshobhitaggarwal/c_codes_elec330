#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "useful_functions.h"

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


// Function to convert a string of numbers (separated by spaces) to an array of integers
// args str: pointer to the string with numbers
// args num_integers: pointer to the integer array to save the numbers
// returns pointer to the integer array

int* string_to_int_array(const char* str, int* num_integers) {
    char* token;
    int* int_array = NULL;
    int i = 0;

    // Tokenize the string by spaces
    token = strtok((char*)str, " "); 

    // Count the number of integers
    while (token != NULL) {
        i++;
        token = strtok(NULL, " ");
    }

    *num_integers = i; 

    // Allocate memory for the integer array
    int_array = (int*)malloc(i * sizeof(int)); 

    if (int_array == NULL) {
        //Memory Allocation failed. Handling required
        return NULL;
    }

    // Reset token pointer
    token = strtok((char*)str, " "); 
    i = 0;

    // Convert each string to an integer and store in the array
    while (token != NULL) {
        int_array[i] = string_to_int(token);
        token = strtok(NULL, " ");
        i++;
    }

    return int_array;
}