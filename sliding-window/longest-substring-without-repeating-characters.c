#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SIZE 128

int lengthOfLongestSubstring(char* s) {
    if (s == NULL) {
        return 0;
    }
    int last[SIZE];
    for (int i = 0; i < SIZE; i++) {
        last[i] = -1;
    }
    int start = 0;
    int ans = 0;
    for (int end = 0; s[end] != '\0'; end++) {
        char c = s[end];  
        if (last[c] != -1) {
            start = MAX(start, last[c] + 1);
        }
        ans = MAX(ans, end - start + 1);
        last[c] = end;
    }
    return ans;
}
