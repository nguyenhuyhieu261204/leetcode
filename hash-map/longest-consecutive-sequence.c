#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100003

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

int hash(int key)
{
    if (key < 0)
        key = -key;
    return key % TABLE_SIZE;
}

Node *find(int key)
{
    int idx = hash(key);
    Node *cur = hashTable[idx];
    while (cur)
    {
        if (cur->key == key)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

void put(int key, int value)
{
    int idx = hash(key);
    Node *cur = hashTable[idx];

    while (cur)
    {
        if (cur->key == key)
        {
            cur->value = value;
            return;
        }
        cur = cur->next;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = hashTable[idx];
    hashTable[idx] = node;
}

int get(int key)
{
    Node *node = find(key);
    return node ? node->value : 0;
}

int longestConsecutive(int *nums, int numsSize)
{
    int ans = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int num = nums[i];
        if (find(num))
            continue;
        int left = get(num - 1);
        int right = get(num + 1);
        int sum = left + right + 1;
        put(num, sum);
        put(num - left, sum);
        put(num + right, sum);
        if (sum > ans)
            ans = sum;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
