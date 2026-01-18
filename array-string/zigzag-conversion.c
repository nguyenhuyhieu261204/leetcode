#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* str, int numRows) {
    int len = strlen(str);
    if (numRows == 1 || numRows >= len) return str;
    char* ans = malloc(len + 1);
    int curIdx = 0;
    for (int i=0; i<numRows; i++) {
        int cycle = 2 * (numRows - 1);
        for (int j=i; j<len; j+=cycle) {
            ans[curIdx++] = str[j];
            int diag = j + cycle - 2 * i;
            if (i != 0 && i != numRows - 1 && diag < len) {
                ans[curIdx++] = str[diag];
            }
        } 
    }
    ans[curIdx] = '\0';
    return ans;
}

int main() {


    return 0;
}