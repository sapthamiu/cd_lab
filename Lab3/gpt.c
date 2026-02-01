#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    /* Arithmetic operators */
    printf("Addition: %d\n", a + b);
    printf("Subtraction: %d\n", a - b);
    printf("Multiplication: %d\n", a * b);

    /* Compound assignment operators */
    a += b;     // a = a + b
    printf("After a += b, a = %d\n", a);

    a *= 2;     // a = a * 2
    printf("After a *= 2, a = %d\n", a);

    /* Increment and decrement */
    b++;
    printf("After b++, b = %d\n", b);

    b--;
    printf("After b--, b = %d\n", b);

    /* Relational and logical operators with if-else */
    if (a > b && b != 0) {
        printf("a is greater than b and b is not zero\n");
    } else if (a == b || !a) {
        printf("a is equal to b OR a is zero\n");
    } else {
        printf("a is less than b\n");
    }

    return 0;
}