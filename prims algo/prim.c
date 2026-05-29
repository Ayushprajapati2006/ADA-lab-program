#include <stdio.h>

#define INF 999

int main() {

    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter cost adjacency matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int visited[n];

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    int minCost = 0;
    int edges = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1) {

        int min = INF;
        int a = -1, b = -1;

        for(int i = 0; i < n; i++) {

            if(visited[i]) {

                for(int j = 0; j < n; j++) {

                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(a != -1 && b != -1) {

            printf("%d --> %d  Cost = %d\n", a, b, min);

            minCost += min;
            visited[b] = 1;

            edges++;
        }
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}