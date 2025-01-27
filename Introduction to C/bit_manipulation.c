#include <stdio.h>

int main() {
    unsigned int num1 = 10, num2 = 5;

    // Bitwise AND (&)
    unsigned int and_result = num1 & num2;
    printf("Bitwise AND: %d & %d = %d\n", num1, num2, and_result);

    // Bitwise OR (|)
    unsigned int or_result = num1 | num2;
    printf("Bitwise OR: %d | %d = %d\n", num1, num2, or_result);

    // Bitwise XOR (^)
    unsigned int xor_result = num1 ^ num2;
    printf("Bitwise XOR: %d ^ %d = %d\n", num1, num2, xor_result);

    // Left Shift (<<)
    unsigned int left_shift_result = num1 << 2;
    printf("Left Shift: %d << 2 = %d\n", num1, left_shift_result);

    // Right Shift (>>)
    unsigned int right_shift_result = num2 >> 1;
    printf("Right Shift: %d >> 1 = %d\n", num2, right_shift_result);

    // One's Complement (~)
    unsigned int ones_complement_result = ~num1;
    printf("One's Complement: ~%d = %d\n", num1, ones_complement_result);

    return 0;
}