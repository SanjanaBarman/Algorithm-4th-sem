#include <stdio.h>
#include <stdlib.h>
#define INF 999
int v,count=1;
int D[10][10],P[10][10];
void printSolution()
{
    int i, j;
    printf("Step %d Shortest distance between all pair of nodes \n",count);
    for(i=1; i<=v; i++)
    {
        for(j=1;j<=v;j++) 
        {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Predecessor Matrix for shortest path \n");
    for(i=1; i<=v; i++) 
    {
        for(j=1; j<=v;j++) 
        {
            printf("%d\t", P[i][j]);
        }
        printf ("\n");
    }
    count++;
}

void floydWarshall(int w[][10]) 
{
    int i,j, k;
    for(i=1; i<=v; i++) 
    {
        for(j=1;j<=v;j++) 
        {
            D[i][j] = w[i][j];
            if(w[i][j]==0&&w[i][j]==999)
            P[i][j] = -1;
            else
            P[i][j]=i;
        }
    }
    for(k=1; k<=v; k++) 
    {
        for(i=1; i<=v; i++) 
        {
            for(j=1;j<=v ; j++) 
            {
                if(D[i][j] > D[i][k] + D[k][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
        printSolution();
    }
}

int main() 
{ 
    FILE *fp = fopen("op.txt", "r");
    int i,j;
    if (fp == NULL)
    {
        printf("Error in opening file!!!"); 
        exit(0);
    }
    fscanf(fp,"%d", &v);
    printf("%d\n",v);
    int G[10][10];
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            if((fscanf(fp,"%d",&G[i][j])!=1))
            {
                return 1;
            }
        }
    }
    fclose(fp);
    for(i=1; i<=v; i++) 
    {
        for(j=1;j<=v;j++)
        {
            printf("%d\t", G[i][j]);
        }
        printf("\n");
    }
    floydWarshall(G);
    return 0;
}

/*4
0       999     -2      999
4       0       3       999
999     999     0       2
999     -1      999     0
Step 1 Shortest distance between all pair of nodes
0       999     -2      999
4       0       2       999
999     999     0       2
999     -1      997     0

Predecessor Matrix for shortest path
1       1       1       1
2       2       1       2
3       3       3       3
4       4       1       4
Step 2 Shortest distance between all pair of nodes
0       999     -2      999
4       0       2       999
999     999     0       2
3       -1      1       0

Predecessor Matrix for shortest path
1       1       1       1
2       2       1       2
3       3       3       3
2       4       1       4
Step 3 Shortest distance between all pair of nodes
0       997     -2      0
4       0       2       4
999     999     0       2
3       -1      1       0

Predecessor Matrix for shortest path
1       3       1       3
2       2       1       3
3       3       3       3
2       4       1       4
Step 4 Shortest distance between all pair of nodes
0       -1      -2      0
4       0       2       4
5       1       0       2
3       -1      1       0

Predecessor Matrix for shortest path
1       4       1       3
2       2       1       3
2       4       3       3
2       4       1       4

--------------------------------
Process exited after 0.06974 seconds with return value 0
Press any key to continue . . .---*/
