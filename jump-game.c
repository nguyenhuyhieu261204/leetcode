#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/**
 * Problem 55: Jump Game
 * Difficulty: Medium
 * Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * Example 1:
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * Example 2:
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 * Constraints:
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i] <= 10^5
 * 
 * @param {int[]} nums
 * @return {bool}
 */
bool canJumpV1(int* nums, int numsSize) {
    int maxReachable = 0, i;

    for (i = 0; i < numsSize; i++) {
        if (i > maxReachable) return false;
        maxReachable = MAX(maxReachable, i + nums[i]);
    }
    return true;
}


/**
 * Problem 55: Jump Game
 * Difficulty: Medium
 * Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * Example 1:
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * Example 2:
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 * Constraints:
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i] <= 10^5
 * 
 * @param {int[]} nums
 * @return {bool}
 */
int canJumpV2(int* nums, int numsSize) {
    bool dp[numsSize];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    int i = 0;
    
    for (i = 0; i < numsSize; i++) {
        if (!dp[i]) continue;
        int furthestJump = (i + nums[i] < numsSize - 1) ? i + nums[i] : numsSize - 1;
        for (int j = i + 1; j <= furthestJump; j++) {
            dp[j] = true;
        }
    }

    return dp[numsSize - 1];
}

int main() {
    int nums1[] = {2, 3, 1, 1, 4};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Can jump (Example 1): %s\n", canJumpV1(nums1, size1) ? "true" : "false");

    return 0;
}