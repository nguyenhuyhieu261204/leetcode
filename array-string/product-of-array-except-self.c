#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i=0; i<numsSize; i++) {
        answer[i] = 1;
    }
    for (int i=1; i<numsSize; i++) {
        answer[i] = answer[i-1] * nums[i-1];
    }
    int product = 1;
    for (int i=numsSize-1; i>=0; i--) {
        answer[i] = answer[i] * product;
        product *= nums[i];
    }
    return answer;
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    int arrLengh = sizeof(arr) / sizeof(int);
    int productLength;
    int* products = productExceptSelf(arr, arrLengh, &productLength);
    for (int i=0; i<productLength; i++) {
        printf("%d\n", products[i]);
    }
    free(products);
    return 0;
}