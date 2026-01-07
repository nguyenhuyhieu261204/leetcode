#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * Finds the maximum profit from a single buy-sell transaction.
 * This is a very bad solution with O(n^2) time complexity.
 * @param prices Reference to the vector of stock prices
 * @return Maximum profit achievable
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
int maxProfitV1(const vector<int>& prices) {
    int ans = 0;
    int n = prices.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, prices[j] - prices[i]);  
        }
    }
    return ans;
}


/**
 * Finds the maximum profit from a single buy-sell transaction.
 * This is a better solution with O(n) time complexity.
 * @param prices Reference to the vector of stock prices
 * @return Maximum profit achievable
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxProfitV2(const vector<int>& prices) {
    int ans = 0;
    int minPrice = INT_MAX;
    for (const int& price : prices) {
        minPrice = min(minPrice, price);
        ans = max(ans, price - minPrice);
    }
    return ans;
}

/**
 * Finds the maximum profit from a single buy-sell transaction.
 * This is the solution that better than V1 using dynamic programming concept.
 * @param prices Reference to the vector of stock prices
 * @return Maximum profit achievable
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(n)
 */
int maxProfitV3(const vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return;
    vector<int> dp(n, 0);
    int minPrices = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrices = min(minPrices, prices[i]);
        dp[i] = min(dp[i - 1], prices[i] - minPrices);
    }
    return dp[n - 1];
}

int main () {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit (V1): " << maxProfitV1(prices) << endl;
    return 0;
}