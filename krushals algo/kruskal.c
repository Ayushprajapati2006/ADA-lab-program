#include <stdio.h>

#define MAX 20
#define INF 999

int parent[MAX];

/* Find function */
int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

/* Union function */
void unionSet(int i, int j) {
    parent[j] = i;
}

int main() {

    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];

    printf("Enter cost adjacency matrix:\n");

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int minCost = 0;
    int edges = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1) {

        int min = INF;
        int a = -1, b = -1;

        /* Find minimum edge */
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        /* If no cycle */
        if(u != v) {

            printf("%d --> %d  Cost = %d\n", a, b, min);

            minCost += min;
            unionSet(u, v);

            edges++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}