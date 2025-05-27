#include <stdio.h>
#include <math.h>


int main() {
    unsigned int n;
    unsigned int max_sum = 0;
    unsigned int max_number = 1;
    unsigned int sum;

    scanf("%u", &n);


    for (unsigned int i = 1; i <= n; i++) {
        sum = 0;
        for (unsigned int j = 1; j * j <= i; j++)
            if (i % j == 0) {
                if (j * j == i)
                    sum += j;
                else
                    sum += j + i / j;
            }

        if (sum > max_sum) {
            max_sum = sum;
            max_number = i;
        }
    }
    printf("%u %u", max_number, max_sum);
    return 0;
}
