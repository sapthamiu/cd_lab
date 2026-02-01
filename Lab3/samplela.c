#include <stdio.h>

int main() {

    int a = 10;
    float b = 3.5;

    // Input output
    printf("Value of a is %d\n", a);
    printf("Value of b is %.2f\n", b);

    /* Arithmetic */
    int sum = a + b;
    int diff = a - b;
    int prod = a * b;
    float div = a / b;

    /* Relational + logical */
    if(a > b && b != 0) {
        printf("a is greater\n");
    }
    else if(a == b || !a) {
        printf("equal or zero\n");
    }
    else {
        printf("a is smaller\n");
    }

    return 0;
}
