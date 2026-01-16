#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * Finds the maximum profit from a single buy-sell transaction.
 * This is very bad solution with O(n^2) time complexity.
 * @param prices Array of stock prices.
 * @param pricesSize Size of the prices array.
 * @return Maximum profit achievable.
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */
int maxProfitV1(int *prices, int pricesSize) {
    int maxProfit = 0;

    for (int i = 0; i < pricesSize - 1; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            int profit = prices[j] - prices[i];
            maxProfit = MAX(maxProfit, profit);
        }
    }

    return maxProfit;
}

/**
 * Finds the maximum profit from a single buy-sell transaction.
 * This is an optimized solution that better than O(n^2) time complexity.
 * @param prices Array of stock prices.
 * @param pricesSize Size of the prices array.  
 * @return Maximum profit achievable.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int maxProfitV2(int *prices, int pricesSize) {
    if (prices == 0) return 0;
    int *dp = calloc(pricesSize, sizeof(int));
    int minPrice = prices[0];

    for (int i = 1; i < pricesSize; i++) {
        minPrice = MIN(minPrice, prices[i]);
        dp[i] = MAX(dp[i - 1], prices[i] - minPrice);
    }

    int result = dp[pricesSize - 1];
    free(dp);

    return result;
}

/**
 * Finds the maximum profit from a single buy-sell transaction.
 * This is the best solution with O(n) time complexity and O(1) space complexity.
 * @param prices Array of stock prices.
 * @param pricesSize Size of the prices array.  
 * @return Maximum profit achievable.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxProfitV3(int *prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 1; i < pricesSize; i++) {
        minPrice = MIN(minPrice, prices[i]);
        maxProfit = MAX(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfitV3(prices, pricesSize);
    printf("Maximum Profit: %d\n", result);
    return 0;
}