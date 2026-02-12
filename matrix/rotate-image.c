void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int rowSize = matrixSize;
    int colSize = matrixSize;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = i; j < rowSize; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize / 2; j++)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][colSize - 1 - j];
            matrix[i][colSize - 1 - j] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
