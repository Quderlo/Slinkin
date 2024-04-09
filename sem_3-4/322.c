#include <stdio.h>

int main() {
    unsigned int n;
    unsigned int sum = 0;
    unsigned int max_sum = 0;
    unsigned int max_number = 1;
    scanf("%u", &n);
    
    for (unsigned int i = 1; i <= n; i++) {
        sum = 0;
        //printf("\n %u delitsy ", i);
        for (unsigned int j = 1; j <= i; j++) {
            if (i % j == 0) {
                sum += j;
                //printf("%u ", j);
            }
        }
        
        if (max_sum < sum) {
            max_sum = sum;
            max_number = i;
        }
    }
    printf("%u %u", max_number, max_sum);
    return 0;
}
