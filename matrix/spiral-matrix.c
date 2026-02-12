#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int rowSize = matrixSize;
    int colSize = matrixColSize[0];
    int *ans = malloc(rowSize * colSize * sizeof(int));
    int ansIdx = 0;
    int top = 0, bottom = rowSize - 1;
    int left = 0, right = colSize - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans[ansIdx++] = matrix[top][i];
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans[ansIdx++] = matrix[i][right];
        }
        right--;
        if (top <= bottom && left <= right)
        {
            for (int i = right; i >= left; i--)
            {
                ans[ansIdx++] = matrix[bottom][i];
            }
            bottom--;
        }
        if (top <= bottom && left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans[ansIdx++] = matrix[i][left];
            }
            left++;
        }
    }
    *returnSize = ansIdx;
    return ans;
}

void main()
{

    return 0;
}