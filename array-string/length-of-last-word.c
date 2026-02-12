#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* str) {
    int len = strlen(str);
    int ans = 0;
    int hasWord = 0;
    for (int i=len-1; i>=0; i--) {
        if (hasWord == 0 && str[i] == ' ') continue;
        if (hasWord == 1 && str[i] == ' ') return ans;
        ans ++;
        hasWord = 1;
    }
    return ans;
}

int main() {
    // Test case 1
    char str1[] = "Hello World";
    printf("Input: \"%s\"\n", str1);
    printf("Length of last word: %d\n\n", lengthOfLastWord(str1));

    // Test case 2
    char str2[] = "   fly me   to   the moon  ";
    printf("Input: \"%s\"\n", str2);
    printf("Length of last word: %d\n\n", lengthOfLastWord(str2));

    // Test case 3
    char str3[] = "luffy is still joyboy";
    printf("Input: \"%s\"\n", str3);
    printf("Length of last word: %d\n\n", lengthOfLastWord(str3));

    // Test case 4 - single word
    char str4[] = "Hello";
    printf("Input: \"%s\"\n", str4);
    printf("Length of last word: %d\n\n", lengthOfLastWord(str4));

    // Test case 5 - trailing spaces
    char str5[] = "Hello ";
    printf("Input: \"%s\"\n", str5);
    printf("Length of last word: %d\n", lengthOfLastWord(str5));

    return 0;
}