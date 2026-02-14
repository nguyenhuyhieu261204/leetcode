#include <stdbool.h>

bool isIsomorphic(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    int hashTable1[256];
    int hashTable2[256];
    for (int i = 0; i < 256; i++)
    {
        hashTable1[i] = -1;
        hashTable2[i] = -1;
    }

    for (int i = 0; t[i] != '\0'; i++)
    {
        int sc = s[i];
        int tc = t[i];
        if (hashTable1[sc] == -1 && hashTable2[tc] == -1)
        {
            hashTable1[sc] = tc;
            hashTable2[tc] = sc;
        }
        else
        {
            if (hashTable1[sc] != tc)
                return false;
        }
    }
    return true;
}

bool isIsomorphic(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    int hashTable1[256];
    int hashTable2[256];

    for (int i = 0; s[i] != '\0'; i++)
    {
        int sc = s[i];
        int tc = t[i];
        if (hashTable1[sc] != hashTable2[tc])
            return false;
        hashTable1[sc] = i + 1;
        hashTable2[tc] = i + 1;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
