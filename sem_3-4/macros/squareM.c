#include <stdio.h>
#include <math.h>
#include <float.h>
#define squareM(A, B, C, NUM, X1, X2) { \
    double discriminant = (B) * (B) - 4 * (A) * (C); \
    if (discriminant < -FLT_EPSILON) { \
        NUM = 0; \
        } else if (discriminant > FLT_EPSILON) { \
            NUM = 2; \
            x1 = (-(B) + sqrt(discriminant)) / (2.0 * (A)); \
            x2 = (-(B) - sqrt(discriminant)) / (2.0 * (A)); \
            } else { \
               NUM = 1; \
               x1 = (-(B)) / (2.0 * (A)); \
            } \
}

int main(void) {
    int a, b, c, num;
    float x1, x2;
    printf("Please enter a number A:");
    scanf("%d", &a);
    printf("Please enter a number B:");
    scanf("%d", &b);
    printf("Please enter a number C:");
    scanf("%d", &c);
    squareM(a, b, c, num, x1, x2);
    switch (num) {
        case 0: printf("Discriminant is below zero, root is complex number"); break;
        case 1: printf("Equation root is %f", x1); break;
        case 2: printf("Equation roots ares %f and %f", x1, x2); break;
        default: printf("Error"); break;
    }

}
