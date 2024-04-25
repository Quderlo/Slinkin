#include <stdio.h>

void func(char input_string[], unsigned int lenght, unsigned int num) {
	if (num > lenght || num < 0) {
		printf("Start number is not in array");
		return;
	}
	
	for (unsigned int i = num - 1; i < lenght; i++) {
        if (input_string[i] == '0') {
            input_string[i] = '1';
        } else if (input_string[i] == '1') {
            input_string[i] = '0';
        }
    }
	
    printf("String is: %s\n", input_string);
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
    printf("Write number when we start replacing 1 <= n <= %llu \n", 
		sizeof(str) - 1);
    scanf("%u", &number);

    func(str, len, number);
    
    return 0;
}
