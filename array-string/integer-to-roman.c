#include <stdlib.h>
#include <string.h>
#define MAX_BYTE 16

char* intToRoman(int num) {
    char* romanValue = malloc(MAX_BYTE * sizeof(char));
    romanValue[0] = '\0';
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    char* romanSymbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    for (int i=0; i<13; i++) {
        while (num >= values[i]) {
            strcat(romanValue, romanSymbol[i]);
            num -= values[i];
        }
    }
    return romanValue;
}