#include <stdio.h>

int main() {
    unsigned int m, x;
    int ch1, ch2;
    float approximation;
    float check_approximation;
    
    printf("Write x: ");
    scanf("%u", &x);
    
    printf("Write len(a) m: ");
    scanf("%u", &m);
   
    float a[m];
    
    for (unsigned int i = 0; i < m; i++) {
		printf("Write characters in a[%u]: ", i + 1);
        scanf("%f", &a[i]);
    }
    
    approximation = x - (a[0] + a[1]) / 2;
	for (unsigned int i = 0; i < m; i++) {
		for (unsigned int j = 0; j < m; j++) {
			if (i == j)
				continue;
				
			check_approximation = x - (a[i] + a[j]) / 2;
			//printf("%f = %f %f\n", check_approximation, a[i], a[j]);
			if (approximation > check_approximation) {
				ch1 = a[i];
				ch2 = a[j];
				approximation = check_approximation;
			}
		}
		
		if (approximation == 0)
			break;
	}
	
	printf("Result: %u %u", ch1, ch2);
    
    return 0;
}
