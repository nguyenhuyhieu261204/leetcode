#include <iostream>
#include <vector>

using namespace std;

/**
 * Finds the maximum profit from multiple buy-sell transactions.
 * This is the best solution with O(n) time complexity.
 * @param prices Reference to the vector of stock prices
 * @return Maximum profit achievable
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxProfitV1(const vector<int>& prices) {
    int ans = 0;
    int n = prices.size();
    if (n == 1) return 0;
    for (int i = 1; i < n; ++i) {
        if (prices[i] > prices[i - 1]) {
            ans += prices[i] - prices[i - 1];
        }
    }
    return ans;
}

/**
 * Finds the maximum profit from multiple buy-sell transactions.
 * This is a good solution with O(n) time complexity using dynamic programming concept.
 * @param prices Reference to the vector of stock prices
 * @return Maximum profit achievable
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int maxProfitV2(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<int> dp(n, 0);
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (prices[i] > prices[i - 1]) {
            dp[i] += prices[i] - prices[i - 1];
        }
    }
    return dp[n - 1];
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfitV1(prices) << endl;
    return 0;
}