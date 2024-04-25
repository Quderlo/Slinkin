#include <stdio.h>

void Binary(unsigned char num) {
    unsigned int size = sizeof(num) * 8;
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

void PrintRawBinary(unsigned char num1, unsigned char num2) {
	printf("Binary numbers: \n");
	Binary(num1);
	Binary(num2);
	printf("||||||||\n");
}

int main() {
    unsigned char num1, num2;
    unsigned char res;
    printf("Enter a number: ");
	scanf("%hhu", &num1);
	printf("Enter second number: ");
	scanf("%hhu", &num2);
    
    printf("1. Bit AND (&)\n");
    res = num1 & num2;
	PrintRawBinary(num1, num2);
	Binary(res);
	printf("\n");
	
    printf("2. Bit OR (|)\n");
    res = num1 | num2;
	PrintRawBinary(num1, num2);
	Binary(res);
	printf("\n");
	
	printf("3. Shift >> 1)\n");
    res = num1 >> 1;
	Binary(num1);
	printf("||||||||\n");
	Binary(res);
	printf("\n");
	
	printf("4. Shift << 1)\n");
    res = num1 << 1;
	Binary(num1);
	printf("||||||||\n");
	Binary(res);
	printf("\n");

    return 0;
}
