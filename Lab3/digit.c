#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int c = 10;

    if (a == b) {
        printf("a is equal to b\n");
    }

    if (a != b) {
        printf("a is not equal to b\n");
    }

    if (a < b) {
        printf("a is less than b\n");
    }

    if (b > a) {
        printf("b is greater than a\n");
    }

    if (a <= c) {
        printf("a is less than or equal to c\n");
    }

    if (b >= c) {
        printf("b is greater than or equal to c\n");
    }

    a = b;   // assignment
    c = a;   // assignment

    return 0;
}
