#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool wordIsUsed(char *hashTable[], char *word)
{
    for (int i = 0; i < 26; i++)
    {
        if (hashTable[i] && strcmp(hashTable[i], word) == 0)
            return true;
    }
    return false;
}

bool wordPattern(char *pattern, char *s)
{
    char *hashTable[26] = {NULL};
    char *token = strtok(s, " ");
    for (int i = 0; pattern[i] != '\0'; i++)
    {
        if (token == NULL)
            return false;
        int idx = pattern[i] - 'a';
        if (hashTable[idx] == NULL)
        {
            if (wordIsUsed(hashTable, token))
                return false;
            hashTable[idx] = token;
        }
        else
        {
            if (strcmp(hashTable[idx], token) != 0)
                return false;
        }
        token = strtok(NULL, " ");
    }
    if (token != NULL)
        return false;

    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
