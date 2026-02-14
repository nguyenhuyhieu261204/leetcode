#include <stdbool.h>

bool canConstruct(char *ransomNote, char *magazine)
{
    int hashTable[26] = {0};
    for (int i = 0; magazine[i] != '\0'; i++)
    {
        hashTable[magazine[i] - 'a']++;
    }
    for (int i = 0; ransomNote[i] != '\0'; i++)
    {
        if (hashTable[ransomNote[i] - 'a'] == 0)
            return false;
        hashTable[ransomNote[i] - 'a']--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
