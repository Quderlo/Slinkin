#include <stdio.h>
#define testbitM(A, B) (((B) >= 0 && (B) < 64) ? ( ((A) & (1LL << (B))) ? 1 : 0 ) : -1 )


void BinaryView(long long int num) {
    long long int size = sizeof(num) * 8;
    for (long long int i = size - 1; i >= 0; i--) {
        printf("%lld", (num >> i) & 1);
        
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

int main() {
    long long int A, B;

    printf("Write number A: ");
    scanf("%lld", &A);
    
    BinaryView(A);

    printf("Write the bit position B (from 0 to 63): ");
    scanf("%lld", &B);

    long long int result = testbitM(A, B);
    printf("%lld", result);

    return 0;
}
