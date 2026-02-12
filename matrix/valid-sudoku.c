#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char c = board[i][j];
            if (c == '.')
                continue;
            int ditgit = c - '1';
            int mask = 1 << ditgit;
            int boxIndex = (i / 3) * 3 + (j / 3);
            if ((rows[i] & mask) || (cols[j] & mask) || (boxes[boxIndex] & mask))
                return false;
            rows[i] |= mask;
            cols[j] |= mask;
            boxes[boxIndex] |= mask;
        }
    }
    return true;
}

void main()
{

    return 0;
}