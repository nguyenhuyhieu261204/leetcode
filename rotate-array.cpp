#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

/**
 * Rotates the array to the right by k steps.
 * This is a straightforward solution using an auxiliary array.
 * @param arr Reference to the vector of integers to be rotated
 * @param k   Number of steps to rotate the array
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void rotateArrayV1(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    if (k == 0) return;
    vector<int> tmp(n);
    for (int i = 0; i < n; ++i) {
        tmp[(i + k) % n] = arr[i];
    }
    arr = tmp;
}


/**
    * Rotates the array to the right by k steps using the reversal algorithm.
    * This is best solution with O(1) space complexity.
    * @param arr Reference to the vector of integers to be rotated
    * @param k   Number of steps to rotate the array
    *
    * Time Complexity: O(n)
    * Space Complexity: O(1)
*/  
void rotateArrayV2(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    if (k == 0) return;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

/**
 * Rotates the array to the right by k steps using cyclic replacements.
 * This solution uses recursion to simulate cyclic replacement.
 * @param arr Reference to the vector of integers to be rotated
 * @param k   Number of steps to rotate the array
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)  // due to recursion stack
 */
void rotateArrayV3(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    if (k == 0) return;
    function<void(int, int, int)> helper = [&](int start, int current, int prevValue) {
        int nextIndex = (current + k) % n;
        int nextValue = arr[nextIndex];
        arr[nextIndex] = prevValue;
        if (nextIndex != start) {
            helper(start, nextIndex, nextValue);
        }
    };
    for (int i=0; i<gcd(n,k); ++i) {
        helper(i, i, arr[i]);
    }
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // Using rotateArrayV1
    vector<int> arr1 = arr;
    rotateArrayV1(arr1, k);
    cout << "After rotateArrayV1: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;

    // Using rotateArrayV2
    vector<int> arr2 = arr;
    rotateArrayV2(arr2, k);
    cout << "After rotateArrayV2: ";
    for (int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    // Using rotateArrayV3
    vector<int> arr3 = arr;
    rotateArrayV3(arr3, k);
    cout << "After rotateArrayV3: ";
    for (int num : arr3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}