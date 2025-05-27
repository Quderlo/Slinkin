#include <stdio.h>
#include <math.h>

int main() {
    unsigned int n;
    unsigned int r;
    unsigned int b;
    unsigned int a;


    scanf("%u", &n);

    for (unsigned int i = 1; i < n; i++) {

        a = i;
        b = n;


        while (a != 0) {
            r = b % a;
            b = a;
            a = r;
        }

	# Если число простое то цикл закончится на и b = 1
        if (b == 1) {
            printf("%u ", i);
        }
    }

    return 0;
}
