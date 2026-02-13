#include <stdlib.h>

/**
 * Using extra array
 * Time complexity: O(m*n)
 * Space complexity: O(m+n)
 */
void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    int rowSize = matrixSize;
    int colSize = matrixColSize[0];

    int *rows = calloc(rowSize, sizeof(int));
    int *cols = calloc(colSize, sizeof(int));

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (rows[i] == 1 || cols[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    free(rows);
    free(cols);
}

/**
 * Using maker
 * Time complexity: O(m*n)
 * Space complexity: O(1)
 */
void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    int rowSize = matrixSize;
    int colSize = matrixColSize[0];

    int zeroInFirstRow = 0;
    int zeroInFirstCol = 0;

    for (int i = 0; i < colSize; i++)
    {
        if (matrix[0][i] == 0)
        {
            zeroInFirstRow = 1;
            break;
        }
    }

    for (int i = 0; i < rowSize; i++)
    {
        if (matrix[i][0] == 0)
        {
            zeroInFirstCol = 1;
            break;
        }
    }

    for (int i = 1; i < rowSize; i++)
    {
        for (int j = 1; j < colSize; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < rowSize; i++)
    {
        for (int j = 1; j < colSize; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (zeroInFirstRow == 1)
    {
        for (int i = 0; i < colSize; i++)
        {
            matrix[0][i] = 0;
        }
    }

    if (zeroInFirstCol == 1)
    {
        for (int i = 0; i < rowSize; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
