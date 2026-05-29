#include <stdio.h>

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int main() {

    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    printf("Enter profits of items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    printf("Enter weights of items:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

    /* Build DP table */
    for(int i = 0; i <= n; i++) {

        for(int w = 0; w <= W; w++) {

            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i - 1] <= w)
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    return 0;
}