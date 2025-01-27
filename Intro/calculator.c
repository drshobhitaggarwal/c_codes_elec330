#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter operator (+, -, *, /): ");
    if (scanf(" %c", &operator) != 1) {
        printf("Invalid operator input.\n");
        return 1;
    }

    printf("Enter two operands: ");
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("Invalid operand input.\n");
        return 1;
    }

    if (operator == '+') {
        result = num1 + num2;
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
    } else if (operator == '-') {
        result = num1 - num2;
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
    } else if (operator == '*') {
        result = num1 * num2;
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
    } else if (operator == '/') {
        if (num2 == 0) {
            printf("Error: Division by zero.\n");
            return 1;
        }
        result = num1 / num2;
        printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
    } else {
        printf("Invalid operator.\n");
        return 1;
    }

    return 0;
}