#include <stdio.h>
#define maxM(A, B, C) ((A > B && A > C) ? A : (B > A && B > C) ? B : C)

int main() {
    int A, B, C;

    printf("Write number A: ");
    scanf("%d", &A);

    printf("Write number B: ");
    scanf("%d", &B);
    
    printf("Write number C: ");
    scanf("%d", &C);

    int result = maxM(A, B, C);
    printf("%d", result);

    return 0;
}
