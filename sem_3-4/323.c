#include <stdio.h>

int main() {
    unsigned int n;
    char mutually_simple = 1;

    scanf("%u", &n);
    
    for (unsigned int i = 1; i < n; i++) {
        //printf("\n %u delitsy ", i);
        mutually_simple = 1;
        for (unsigned int j = 2; j <= i; j++) {
            if (i % j == 0 && n % j == 0) {
				mutually_simple = 0;
                break;
            }
       }
		if (mutually_simple) {
			printf("%u ", i);
        }
        
    }
    return 0;
}
