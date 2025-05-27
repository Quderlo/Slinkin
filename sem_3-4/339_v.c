#include <stdio.h>

int main() {
    unsigned int m;
    char present;
    unsigned int result = 0;

    printf("Write len:");
    scanf("%u", &m);


    unsigned int a[m];

    for (unsigned int i = 0; i < m; i++) {
        printf("Write characters in a[%u]:", i + 1);
        scanf("%u", &a[i]);
    }


    for (unsigned int i = 0; i < m; ++i) {
        present = 0;
        for (unsigned int j = 0; j < i; ++j) {
            if (a[i] == a[j]) {
                present = 1;
                break;
            }
        }
        if (!present)
            ++result;
    }


    if (result)
        printf("%d", result);
    else
        printf("None");

    return 0;
}
