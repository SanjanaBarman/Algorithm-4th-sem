#include <stdio.h>
#include <stdlib.h>
#define INF 999
int v,count=1;

void printSolution(int D[][v], int P[][v])
{
    int i, j;
    printf("Step %d Shortest distance between all pair of nodes \n",count);
    for(i=0; i<v; i++)
    {
        for(j=0;j<v;j++) 
        {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
   /* printf("Predecessor Matrix for shortest path \n");
    for(i=0; i<v; i++) 
    {
        for(j=0; j<v;j++) 
        {
            printf("%d\t", P[i][j]);
        }
        printf ("\n");
    }*/
    count++;
}

void floydWarshall(int w[][v],int v) 
{
    int i,j, k;
    int D[v][v], P[v][v];
    for(i=0; i<v; i++) 
    {
        for(j=0;j<v;j++) 
        {
            D[i][j] = w[i][j];
            P[i][j] = 0;
        }
    }
    for(k=0; k<v; k++) 
    {
        for(i=0; i<v; i++) 
        {
            for(j=0;j<v ; j++) 
            {
                if(abs(D[i][j]) > abs(D[i][k] + D[k][j]))
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k+1;
                }
            }
        }
        printSolution(D, P);
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
    int G[v][v];
    for(i=0; i<v; i++)
    {
        for(j=0;j<v;j++)
        {
            if((fscanf(fp,"%d",&G[i][j])!=1))
            
            {
            	
                return 1;
            }
        }
    }
    fclose(fp);
    for(i=0; i<v; i++) 
    {
        for(j=0;j<v;j++)
        {
            printf("%d\t", G[i][j]);
        }
        printf("\n");
    }
    floydWarshall(G,v);
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

Step 2 Shortest distance between all pair of nodes
0       999     -2      999
4       0       2       999
999     999     0       2
3       -1      1       0

Step 3 Shortest distance between all pair of nodes
0       997     -2      0
4       0       2       4
999     999     0       2
3       -1      1       0

Step 4 Shortest distance between all pair of nodes
0       -1      1       0
4       0       2       4
5       1       0       2
3       -1      1       0


--------------------------------*/
