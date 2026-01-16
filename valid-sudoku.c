#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 1) return nums;
    int* answer = malloc(numsSize * sizeof(int));
    memset(answer, -1, numsSize * sizeof(int));
    int i = 0;
    for (i=1; i<nums; i++) {
        answer[i] = answer[i] * answer[i-1];
    }
    for (i=numsSize-2; i>=0; i--) {
        nums[i] = nums[i] * nums[i-1];
        answer[i] *= nums[i];
    }
    *returnSize = numsSize;
    return answer;
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    int arrLengh = sizeof(arr) / sizeof(int);
    int* productLength;
    int* products = productExceptSelf(arr, arrLengh, productLength);
    for (int i=0; i<productLength; i++) {
        printf("%d\n", products[i]);
    }

    return 0;
}