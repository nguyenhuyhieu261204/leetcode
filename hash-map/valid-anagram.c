#include <stdbool.h>
#include <string.h>

bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    int hashTable[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        hashTable[s[i] - 'a']++;
        hashTable[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hashTable[i] != 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
