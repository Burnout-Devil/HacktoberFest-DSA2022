#include<stdio.h>
main()
{
    int m[10][10],source,i,j,n;
    printf("enter the no of vertices\n");
    scanf("%d",&n);
    printf("enter the connections 0 or 1\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("(%d,%d)\n",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    source=4;
    bfs(m,n,source);
}
void bfs(int m[10][10],int n,int s)
{
    int queue[10],rear=0,front=0,u,i,j,visited[10];
    for(i=0;i<n;i++)
        visited[i]=0;
        queue[rear]=s;
        visited[s]=1;
        printf("The bfs is \n");
    while(front<=rear)
    {
        u=queue[front];
        printf("%d\t",u);
        front=front+1;
        for(i=0;i<n;i++)
        {
            if(m[u][i]==1 && visited[i]==0)
            {
               visited[i]=1;
               rear=rear+1;
               queue[rear]=i;
            }
        }
    }
}
