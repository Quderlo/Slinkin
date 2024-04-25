#include <stdio.h>

#define squarenumM(A,B,C) ((B * B - 4 * A * C) < 0 ? 0 : ((B * B - 4 * A * C) > 0 ? 2 : 1))

int main() {
    int A, B, C;

    printf("Write number A: ");
    scanf("%d", &A);

    printf("Write number B: ");
    scanf("%d", &B);
    
    printf("Write number C: ");
    scanf("%d", &C);
    
    int result = squarenumM(A, B, C);
    printf("%d", result);

    return 0;
}
