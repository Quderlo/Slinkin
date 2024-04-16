#include <stdio.h>
#include <stdlib.h>

char *string_replace(char *str, unsigned int len, unsigned int start) {
    for (unsigned int i = 0; i < len; i++) {
        modified_str[i] = str[i];
    }

    for (unsigned int i = start - 1; i < len; i++) {
        if (modified_str[i] == '0') {
            modified_str[i] = '1';
        } else if (modified_str[i] == '1') {
            modified_str[i] = '0';
        }
    }
    
    modified_str[len] = '\0';

    return modified_str;
}

int main() {
    unsigned int len = 1;
	
    printf("Write length: ");
    scanf("%u", &len);
	
    char str[len + 1];
	
    printf("Write string: ");
    getchar();
	
    fgets(str, sizeof(str), stdin);
    
    unsigned int number;
    printf("Write number when we start replacing 1 <= n <= %u \n", len);
    scanf("%u", &number);
	
    char *modified_str = string_replace(str, len, number);
	
    printf("String is: %s\n", modified_str);
	
    free(modified_str);

    return 0;
}
