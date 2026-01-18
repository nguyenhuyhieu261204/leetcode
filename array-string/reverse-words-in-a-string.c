#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* str) {
    int originLen = strlen(str);
    char* ans = malloc(originLen + 1);
    int i = originLen - 1;
    int curIdx = 0;
    while (i >= 0) {
        while (i >= 0 && str[i] == ' ') i --;
        if (i < 0) break;
        int end = i;
        while (i >=0 && str[i] != ' ') i --;
        int start = i + 1;
        for (int j=start; j<=end; j++) {
            ans[curIdx ++] = str[j];
        }
        ans[curIdx ++] = ' ';
    }
    if (curIdx > 0) curIdx --;
    ans[curIdx] = '\0';
    return ans;
}

int main() {
    

    return 0;
}