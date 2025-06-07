#include <stdio.h>
#include <math.h>
#define simpleM(A, Result) { \
    Result = 1; \
    int abs_A = abs(A); \
    if (abs_A < 2) { \
        Result = 0; \
    } else \
    for (int i = 2; i * i <= abs_A; ++i) \
    { \
        if (abs_A % i == 0) { \
            Result = 0;\
            break;\
        } \
    } \
}

int main(void) {
    int a, res;
    printf("Please enter a number:");
    scanf("%d", &a);
    simpleM(a, res);
    printf("The result is: %d", res);
    return 0;
}
