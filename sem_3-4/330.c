#include <stdio.h>

int main(void) {
    unsigned int n;
    scanf("%u", &n);

    for (unsigned int i = 2; i < n; ++i) {
        unsigned int sum_del = 1;


        for (unsigned int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                sum_del += j;

                unsigned int k = i / j;    //100 / 2 = 50
                if (k != j)
                    sum_del += k;

                if (sum_del > i)
                    break;
            }
        }

        if (sum_del == i)
            printf("%u ", i);
    }
    return 0;
}
