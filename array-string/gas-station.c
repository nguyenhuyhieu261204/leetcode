#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalGas = 0;
    int gasRemain = 0;
    int startAt = -1;
    for (int i=0; i<costSize; i++) {
        totalGas += gas[i] - cost[i];
        gasRemain += gas[i] - cost[i];
        if (gasRemain > 0) {
            if (startAt == -1) startAt = i;
        } else {
            gasRemain = 0;
            startAt = -1;
        }
    }
    return totalGas >= 0 ? startAt : -1;
}

int main() {
    int gas[] = { 1, 2, 3, 4, 5 };
    int cost[] = { 3, 4, 5, 1, 2 };
    int gasSize = sizeof(gas) / sizeof(int);
    int costSize = sizeof(cost) / sizeof(int);

    printf("Start At: %d", canCompleteCircuit(gas, gasSize, cost, costSize));

    return 0;
}