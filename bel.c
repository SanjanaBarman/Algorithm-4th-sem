#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <stdbool.h>

int v,e;
int *d;
struct Graph{
	int u,v,wt;
};	
struct Graph G[10];

void printSolution()
{
    int i;
    printf("\n Vertex Distance from Source \n");
    for(i=1; i<=v; i++) 
    {
        printf("%d\t\t%d\n", i, d[i]);
    }
}

void relax(int u,int v,int w)
{
    if (w!=0 && d[u]!=INT_MAX && d[v]>d[u]+w)
    {
        d[v] =d[u]+w;
    }
}

void initializeSingleSource(int s)
{
    int i;
    d=(int*)malloc(v*sizeof(int)); 
    for(i=1; i<=v; i++) 
    {
        d[i] = INT_MAX;
    }
    d[s]=0;
}

bool bellmanFord(int s)
{
    int i,j;
    initializeSingleSource(s);
    for(i=1;i<=v-1; i++)
    { 
        for(j=1;j<=e;j++) 
            { 
                if(d[G[j].u]+G[j].wt<d[G[j].v])
                {
                	d[G[j].v]=d[G[j].u]+G[j].wt;
				}
            }
        }
    for(j=1;j<=e;j++) 
            { 
                if(d[G[j].u]+G[j].wt<d[G[j].v])
                {
                	return false;
				}
            }
    printSolution();
    return true;
}

int main()
{
    int s,i,j;
    bool t;
    FILE *fp = fopen("bel.txt", "r");
    if (fp == NULL)
    {
        printf("Error in opening file!!!"); 
        exit(0);
    }
    fscanf(fp,"%d", &v);
    printf("The no. of vertex %d\n",v);
    fscanf(fp,"%d", &e);
    printf("no. of edge %d\n",e);
    for(i=1;i<=e;i++)
	{
		fscanf(fp,"%d%d%d",&G[i].u,&G[i].v,&G[i].wt);
	}

	for(i=1;i<=e;i++)
	{
		printf("(%d -> %d)-> %d\n",G[i].u,G[i].v,G[i].wt);
	}
	
    fclose(fp);
    printf("Enter the source of vertex:");
    scanf("%d", &s);
    t=bellmanFord(s);
    if(t==false)
    	printf("(-)ve weight cycle exists\n");
    return 0;
}



/*
The no. of vertex 5
no. of edge 6
(1 -> 2)-> 2
(2 -> 3)-> 3
(3 -> 4)-> 4
(4 -> 3)-> -2
(4 -> 5)-> 1
(2 -> 5)-> 10
Enter the source of vertex:1

 Vertex Distance from Source
1               0
2               2
3               5
4               9
5               10

--------------------------------
Process exited after 2.988 seconds with return value 0
Press any key to continue . . .
*/


