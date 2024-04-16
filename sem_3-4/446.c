#include <stdio.h>

int main() {
    unsigned int len = 1;
	
    printf("Write length: ");
    scanf("%u", &len);
	
    char str[len + 1];
	
    printf("Write string: ");
    getchar();
	
    fgets(str, sizeof(str), stdin);
    
    unsigned int number;
    printf("Write number when we start replacing 1 <= n <= %llu \n", 
		sizeof(str) - 1);
    scanf("%u", &number);
	

    for (unsigned int i = number - 1; i < len; i++) {
        if (str[i] == '0') {
            str[i] = '1';
        } else if (str[i] == '1') {
            str[i] = '0';
        }
    }
	
    printf("String is: %s\n", str);
	
    return 0;
}
