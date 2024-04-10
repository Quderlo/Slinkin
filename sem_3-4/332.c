#include <stdio.h>

int main() {
    unsigned int n;
    
    printf("Write n: ");
    scanf("%u", &n);
    
    unsigned int x, y, z, t;
    
    for (x = 0; x * x <= n; x++) {
        for (y = x; y * y <= n; y++) {
            for (z = y; z * z <= n; z++) {
                for (t = z; t * t <= n; t++) {
                    if (x * x + y * y + z * z + t * t == n) {
                        printf("x = %u, y = %u, z = %u, t = %u\n", x, y, z, t);
                    }
                }
            }
        }
    }
    
    return 0;
}
