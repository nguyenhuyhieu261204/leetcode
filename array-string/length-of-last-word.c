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