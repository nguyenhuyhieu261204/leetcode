#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Problem 274: H-Index
 * Difficulty: Medium
 * Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper,
 * return the researcher's h-index.
 * According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each,
 * and the other n − h papers have no more than h citations each.
 * If there are several possible values for h, the maximum one is taken as the h-index.
 * Example 1:
 * Input: citations = [3,0,6,1,5]
 * Output: 3
 * Explanation: [3,0,6,1,5] means the researcher has        
 * 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
 * Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.   
 * 
 * @param {int[]} citations
 * @return {int}
 */
int hIndex(int *hIndex, int citationsSize) {
    int *count = calloc(citationsSize + 1, sizeof(int));

    for (int i = 0; i < citationsSize; i++) {
        if (hIndex[i] >= citationsSize) {
            count[citationsSize] ++;
        } else {
            count[hIndex[i]]++;
        }
    }

    int total = 0;

    for (int i = citationsSize; i >= 0; i--) {
        total += count[i];
        if (total >= i) {
            free(count);
            return i;
        }
    }
    free(count);

    return 0;
}

int main() {


    return 0;
}