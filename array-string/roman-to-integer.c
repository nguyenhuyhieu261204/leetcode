#include <stdio.h>
#include <string.h>

int value(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:    
        return 0;
    }
}

int romanToInt(char* str) {
    int sum = 0;
    int len = strlen(str);
    for (int i=0; i<len-1; i++) {
        if (str[i] == 'I' && (str[i+1] == 'V' || str[i+1] == 'X') ||
            str[i] == 'X' && (str[i+1] == 'L' || str[i+1] == 'C') ||
            str[i] == 'C' && (str[i+1] == 'D' || str[i+1] == 'M')) {
                sum -= value(str[i]);
        } else {
            sum += value(str[i]);
        }
    }
    sum += value(str[len-1]);
    return sum;
}

int main() {

    return 0;
}