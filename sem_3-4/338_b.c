#include <stdio.h>

int main() {
    unsigned int n, m;
    char present = 0;
    
    printf("Write len(a) m: ");
    scanf("%u", &m);
    
    printf("Write len(b) n: ");
    scanf("%u", &n);
    
     unsigned int b[n];
     unsigned int a[m];
    
    for (unsigned int i = 0; i < m; i++) {
		printf("Write characters in a[%u]: ", i + 1);
        scanf("%u", &a[i]);
    }
    
    for (unsigned int i = 0; i < n; i++) {
		printf("Write characters in b[%u]: ", i + 1);
        scanf("%u", &b[i]);
    }
    
    
	printf("Result: ");
    for (unsigned int i = 0; i < m; i++) {
		printf("%u ", a[i]);
	}
    
	for (unsigned int i = 0; i < n; i++) {
		present = 0;
		for (unsigned int j = 0; j < m; j++) {
			if (b[i] == a[j]) {
				present = 1;
				break;
			}
		}
		if (!present)
			printf("%u ", b[i]);
	}
    
    return 0;
}
