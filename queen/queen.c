#include <stdio.h>
#include <stdlib.h>

int x[20], count = 0;

/* Function to check whether queen can be placed */
int place(int k, int i) {

    for(int j = 1; j < k; j++) {

        if(x[j] == i ||
           abs(x[j] - i) == abs(j - k))
            return 0;
    }

    return 1;
}

/* Function to solve N-Queens */
void nQueens(int k, int n) {

    for(int i = 1; i <= n; i++) {

        if(place(k, i)) {

            x[k] = i;

            if(k == n) {

                count++;

                printf("\nSolution %d:\n", count);

                for(int j = 1; j <= n; j++) {
                    for(int p = 1; p <= n; p++) {

                        if(x[j] == p)
                            printf("Q ");
                        else
                            printf(". ");
                    }

                    printf("\n");
                }
            }

            else {
                nQueens(k + 1, n);
            }
        }
    }
}

int main() {

    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    nQueens(1, n);

    if(count == 0)
        printf("No solution exists\n");

    return 0;
}