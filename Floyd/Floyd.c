#include<stdio.h>
#define max 10

int main()
{
    int i,j,k,n;
    printf("Enter no of vertices:");
    scanf("%d",&n);
    printf("Enter the adjecency matrix:\n");
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
        printf("\n");
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][k]+arr[k][j]<arr[i][j])
                {

                   arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }
    printf("The shortest distance adjacecny matrix is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;

}
