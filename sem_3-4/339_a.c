#include <stdio.h>

int main() {
    unsigned int m;
    char present;
	unsigned int result = 0; 
	
    printf("Write len(a) m: ");
    scanf("%u", &m);
    
    
    unsigned int a[m];
    
    for (unsigned int i = 0; i < m; i++) {
		printf("Write characters in a[%u]: ", i + 1);
        scanf("%u", &a[i]);
    }
    
    
    printf("Result: ");
	for (unsigned int i = 0; i < m; i++) {
		present = 0;
		for (unsigned int j = 0; j < m; j++) {
			if (a[i] == a[j] && i != j) {
				present = 1;
			}
		}
		if (!present)
			result++;
	}
	
	printf("%u", result);
    
    return 0;
}
