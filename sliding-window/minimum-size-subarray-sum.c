#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minSubArrayLen(int target, int* nums, int numsSize) {
    int ans = numsSize;
    int left = 0;
    int sum = 0;
    for (int right=0; right<numsSize; right++) {
        sum += nums[right];
        while (sum >= target) {
            ans = MIN(right - left + 1, ans);
            sum -= nums[left];
            left ++;
        }
    }
    return ans == numsSize ? 0 : ans;
}