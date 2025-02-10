#ifndef STRING_TO_INT_H
#define STRING_TO_INT_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int string_to_int(const char* str);
int* string_to_int_array(const char* str, int* num_integers);

#endif // STRING_TO_INT_H