#include <stdio.h>
#include <stdlib.h>

/**
 * Rotates the given array to the right by k steps.
 * This is the bad solution with O(n) time complexity and O(n) space complexity.
 * @param nums Array of integers to be rotated.
 * @param numsSize Size of the nums array.
 * @param k Number of steps to rotate the array.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void rotate(int * nums, int numsSize, int k) {
    if (nums == NULL || numsSize <= 1) return;
    k = k % numsSize;
    int *temp = calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        temp[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
    free(temp);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    rotate(arr, arrSize, k);
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}