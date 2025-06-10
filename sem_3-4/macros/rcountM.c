#include <stdio.h>
#include <stdint.h>   /* uint8_t */

/*----------------------------------------------------------
 * rcountM(A, Result)
 * Считает количество русских букв (UTF-8) в строке A.
 *   A      — const char * или char *;
 *   Result — lvalue-переменная целого типа для ответа.
 *
 * Русские буквы представлены двумя байтами:
 *   Ё  : 0xD0 0x81
 *   А–Я: 0xD0 0x90 … 0xD0 0xBF
 *   а–п: 0xD1 0x80 … 0xD1 0x8F
 *   ё  : 0xD1 0x91
 *----------------------------------------------------------*/
#define rcountM(A, Result)                                            \
do {                                                                  \
    const uint8_t *_p = (const uint8_t *)(A);                         \
    size_t _cnt = 0;                                                  \
                                                                      \
    while (*_p) {                                                     \
        if (*_p == 0xD0) {                                            \
            uint8_t _n = _p[1];                                       \
            if (_n == 0x81 || (_n >= 0x90 && _n <= 0xBF)) {           \
                ++_cnt;                                               \
                _p += 2;                                              \
                continue;                                             \
            }                                                         \
        } else if (*_p == 0xD1) {                                     \
            uint8_t _n = _p[1];                                       \
            if (_n == 0x91 || (_n >= 0x80 && _n <= 0x8F)) {           \
                ++_cnt;                                               \
                _p += 2;                                              \
                continue;                                             \
            }                                                         \
        }                                                             \
        ++_p;                                                         \
    }                                                                 \
    (Result) = _cnt;                                                  \
} while (0)

int main(void)
{
    /* статические примеры */
    char *s1 = "Привет, мир!";
    char *s2 = "123 ABC ёЁ";
    size_t n;

    rcountM(s1, n);
    printf("%s -> %zu russian letters\n", s1, n);   /* ожидаем 9 */

    rcountM(s2, n);
    printf("%s -> %zu russian letters\n", s2, n);   /* ожидаем 2 */

    /* строка от пользователя */
    char buf[256];
    printf("\nWrite a string:");
    if (fgets(buf, sizeof buf, stdin)) {
        rcountM(buf, n);
        printf("String have %zu russian letters.\n", buf, n);
    }
    return 0;
}
