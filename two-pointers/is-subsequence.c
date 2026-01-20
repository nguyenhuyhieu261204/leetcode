#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    int j = 0;
    for (int i=0; i<tLen && j<sLen; i++) {
        if (t[i] == s[j]) {
            j ++;
        }
    }
    return j == sLen;
}