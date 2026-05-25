#include <stdio.h>
#define MAX 100
#define INF 9999

int main()
{
    int n, i, j;
    int cost[MAX][MAX], visited[MAX] = {0};
    int mincost = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(edges < n - 1)
    {
        int min = INF, a = -1, b = -1;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(a != -1 && b != -1)
        {
            printf("%d - %d : %d\n", a, b, min);
            mincost += min;
            visited[b] = 1;
            edges++;
        }
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
