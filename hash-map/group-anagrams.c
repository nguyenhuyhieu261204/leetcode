#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *key;
    char **words;
    int size;
    int cap;
} Group;

char *copyStr(const char *s)
{
    char *p = malloc(strlen(s) + 1);
    strcpy(p, s);
    return p;
}

void sortString(char *s)
{
    int cnt[26] = {0};
    for (int i = 0; s[i]; i++)
        cnt[s[i] - 'a']++;

    int idx = 0;
    for (int c = 0; c < 26; c++)
        while (cnt[c]--)
            s[idx++] = c + 'a';
}

int findGroup(Group *groups, int gSize, char *key)
{
    for (int i = 0; i < gSize; i++)
        if (strcmp(groups[i].key, key) == 0)
            return i;
    return -1;
}

char ***groupAnagrams(char **strs, int strsSize,
                      int *returnSize, int **returnColumnSizes)
{
    Group *groups = malloc(strsSize * sizeof(Group));
    int gSize = 0;

    for (int i = 0; i < strsSize; i++)
    {
        char *key = copyStr(strs[i]);
        sortString(key);

        int idx = findGroup(groups, gSize, key);

        if (idx == -1)
        {
            groups[gSize].key = key;
            groups[gSize].cap = 4;
            groups[gSize].size = 0;
            groups[gSize].words = malloc(4 * sizeof(char *));
            idx = gSize++;
        }
        else
        {
            free(key);
        }

        Group *g = &groups[idx];
        if (g->size == g->cap)
        {
            g->cap *= 2;
            g->words = realloc(g->words, g->cap * sizeof(char *));
        }
        g->words[g->size++] = strs[i];
    }

    char ***ans = malloc(gSize * sizeof(char **));
    *returnColumnSizes = malloc(gSize * sizeof(int));

    for (int i = 0; i < gSize; i++)
    {
        ans[i] = groups[i].words;
        (*returnColumnSizes)[i] = groups[i].size;
    }

    *returnSize = gSize;
    return ans;
}
