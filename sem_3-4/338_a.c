#include <stdio.h>

int main() {
    unsigned int n, m;
    
    printf("Write n: ");
    scanf("%u", &n);
    printf("Write m: ");
    scanf("%u", &m);
    
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
    
    int present = 0;
    
    
    printf("Result: ");
	for (unsigned int i = 0; i < n; i++) {
		present = 0;
		for (unsigned int j = 0; j < m; j++) {
			//printf("%d == %d = %d\n", b[i], a[j], b[i] == a[j]); 
			if (b[i] == a[j]) {
				present = 1;
			}
			//printf("%d", present);
		}
		if (present)
			printf("%d", b[i]);
	}
    
    return 0;
}
