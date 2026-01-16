#include <stdio.h>
#include <stdbool.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/**
 * Problem 45: Jump Game II
 * Difficulty: Medium
 * Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * You can assume that you can always reach the last index.
 * Example 1:
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 
 * @param {int[]} nums
 * @return {int}
 */
int jump(int* nums, int numsSize) {
    if (numsSize == 1) return 0;

    int step = 0;
    int currentEnd = 0;
    int maxReachable = 0;
    int i = 0;

    for (i = 0; i < numsSize; i++) {
        if (i > currentEnd) {
            step++;
            currentEnd = maxReachable;
        }
        maxReachable = MAX(maxReachable, i + nums[i]);
    }

    return step;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Size: %d\n", numsSize);
    int result = jump(nums, numsSize);
    printf("Minimum number of jumps to reach the last index: %d\n", result);    

    return 0;
}