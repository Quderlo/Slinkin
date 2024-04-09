#include <stdio.h>

int main() {
    unsigned int n, m;
    
    printf("Write n: ");
    scanf("%u", &n);
    printf("Write m: ");
    scanf("%u", &m);
    
     unsigned int b[n];
     unsigned int a[m];
    
    for (unsigned int i = 0; i < n; i++) {
		printf("Write characters in a[%u]: ", i + 1);
        scanf("%u", &a[i]);
    }
    
    printf("Write b: ");
    for (unsigned int i = 0; i < m; i++) {
		printf("Write characters in b[%u]: ", i + 1);
        scanf("%u", &b[i]);
    }
    
    char presents[m];
    
    printf("Result: ");
	for (unsigned int i = 0; i < n; i++) {
		presents[i] = 0;
		for (unsigned int j = 0; j < m; j++) {
			if (!presents[i] && i == j) {
				presents[i] = 1;
				printf("%u ", i);
			}
		}
	}
    
    return 0;
}
