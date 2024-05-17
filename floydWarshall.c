#include <stdio.h>
#include <stdlib.h>
#define INF 999
int v;

void printSolution(int D[][v], int P[][v])
{
    int i, j;
    printf("Shortest distance between all pair of nodes \n");
    for(i=0; i<v; i++)
    {
        for(j=0;j<v;j++) 
        {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    printf("Predecessor Matrix for shortest path \n");
    for(i=0; i<v; i++) 
    {
        for(j=0; j<v;j++) 
        {
            printf("%d\t", P[i][j]);
        }
        printf ("\n");
    }
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
                    P[i][j] = P[k][j];
                }
            }
        }
        printSolution(D, P);
    }
}

int main() 
{ 
    FILE *fp = fopen("adjacency1.txt", "r");
    int i,j;
    if (fp == NULL)
    {
        printf("Error in opening file!!!"); 
        exit(0);
    }
    fscanf(fp,"%d", &v);
    int G[v][v];
    for(i=0; i<v; i++)
    {
        for(j=0;j<v;j++)
        {
            if(fscanf(fp, "%d", &G[i][j] != 1))
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
