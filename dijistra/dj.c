#include <stdio.h>

#define MAX 20
#define INF 9999

int main() {

    int n, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];

    printf("Enter cost adjacency matrix:\n");

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            scanf("%d", &cost[i][j]);

            /* Replace 0 with INF except diagonal */
            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    int distance[MAX];
    int visited[MAX];

    /* Initialize distance and visited arrays */
    for(int i = 0; i < n; i++) {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    /* Dijkstra Algorithm */
    for(int count = 1; count < n - 1; count++) {

        int min = INF;
        int nextVertex = -1;

        /* Find nearest unvisited vertex */
        for(int i = 0; i < n; i++) {

            if(!visited[i] && distance[i] < min) {
                min = distance[i];
                nextVertex = i;
            }
        }

        visited[nextVertex] = 1;

        /* Update distances */
        for(int i = 0; i < n; i++) {

            if(!visited[i] &&
               min + cost[nextVertex][i] < distance[i]) {

                distance[i] = min + cost[nextVertex][i];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(int i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i, distance[i]);
    }

    return 0;
}