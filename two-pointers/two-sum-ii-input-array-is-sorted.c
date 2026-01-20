#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* ans = malloc(2*sizeof(int));
    *returnSize = 0;
    int left = 0;
    int right = numbersSize - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum > target) {
            right --;
        } else if (sum < target) {
            left ++;
        } else {
            ans[0] = left + 1;
            ans[1] = right + 1;
            *returnSize = 2;
            break;
        }
    }
    return ans;
}