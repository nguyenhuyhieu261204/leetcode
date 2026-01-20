#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int ans = 0;
    while (left < right) {
        int area = (right - left) * (MIN(height[left], height[right]));
        ans = MAX(area, ans);
        if (height[left] < height[right]) {
            left ++;
        } else if (height[left] > height[right]) {
            right --;
        } else {
            left ++;
            right --;
        }
    }
    return ans;
}