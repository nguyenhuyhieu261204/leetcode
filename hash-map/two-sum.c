#include <stdlib.h>

typedef struct
{
    int key;
    int value;
    int used;
} HashItem;

int hash(int key, int size)
{
    return (key % size + size) % size;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int tableSize = numsSize * 2;
    HashItem *table = (HashItem *)calloc(tableSize, sizeof(HashItem));

    for (int i = 0; i < numsSize; i++)
    {
        int diff = target - nums[i];
        int h = hash(diff, tableSize);

        while (table[h].used)
        {
            if (table[h].key == diff)
            {
                int *result = (int *)malloc(2 * sizeof(int));
                result[0] = table[h].value;
                result[1] = i;
                *returnSize = 2;
                free(table);
                return result;
            }
            h = (h + 1) % tableSize;
        }

        h = hash(nums[i], tableSize);
        while (table[h].used)
        {
            h = (h + 1) % tableSize;
        }
        table[h].key = nums[i];
        table[h].value = i;
        table[h].used = 1;
    }

    free(table);
    *returnSize = 0;
    return NULL;
}
