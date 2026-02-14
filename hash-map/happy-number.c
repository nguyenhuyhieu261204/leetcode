#include <stdbool.h>

int sumOfSquares(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    bool visited[1000] = {false};

    while (n != 1)
    {
        if (visited[n])
            return false;
        visited[n] = true;
        n = sumOfSquares(n);
    }

    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
