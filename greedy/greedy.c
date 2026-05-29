#include <stdio.h>

/* Structure for items */
struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {

    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter profit and weight of each item:\n");

    for(int i = 0; i < n; i++) {

        scanf("%d %d", &item[i].profit, &item[i].weight);

        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    /* Sort items based on profit/weight ratio */
    for(int i = 0; i < n - 1; i++) {

        for(int j = i + 1; j < n; j++) {

            if(item[i].ratio < item[j].ratio) {

                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    float totalProfit = 0.0;

    printf("\nSelected Items:\n");

    for(int i = 0; i < n; i++) {

        if(capacity >= item[i].weight) {

            capacity -= item[i].weight;

            totalProfit += item[i].profit;

            printf("Item with profit %d and weight %d selected completely\n",
                   item[i].profit, item[i].weight);
        }

        else {

            float fraction = capacity / item[i].weight;

            totalProfit += item[i].profit * fraction;

            printf("Item with profit %d and weight %d selected partially\n",
                   item[i].profit, item[i].weight);

            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}