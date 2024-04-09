#include <stdio.h>

int main() {
    unsigned int n;
    unsigned int sum_del = 0;
	
    scanf("%u", &n);
    
    for (unsigned int i = 1; i < n; i++) {
		sum_del = 0;
        for (unsigned int j = 1; j < i; j++) {
            if (sum_del > i)
				break;
				
			if (i % j == 0)
				sum_del += j;
			
       }
       
		if (sum_del == i) {
			printf("%u ", i);
        }
        
    }
    return 0;
}
