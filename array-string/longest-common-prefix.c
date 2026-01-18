#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    int firstLen = strlen(strs[0]);
    for (int i = 0; i < firstLen; i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            if (i >= strlen(strs[j]) || strs[j][i] != c) {
                char* ans = malloc(i + 1); 
                strncpy(ans, strs[0], i);
                ans[i] = '\0';
                return ans;
            }
        }
    }
    char* ans = malloc(firstLen + 1);
    strcpy(ans, strs[0]);
    return ans;
}