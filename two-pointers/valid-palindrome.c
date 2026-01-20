#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char* str) {
    int len = strlen(str);
    if (len == 1) return true;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        while (left < right && !isalnum(str[left])) {
            left ++;
        }
        while (right > left && !isalnum(str[right])) {
            right --;
        }
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left ++;
        right --;
    }
    return true;
}