#include<stdio.h>
#include<stdlib.h>

struct graph{
	int v1;
	int v2;
	int wt;
};

int vertex=6;
int edge=9;

struct graph arr[9]={{0,1,7},{1,2,6},{0,3,8},{3,4,3},{1,3,3},{3,2,4},{2,4,2},{2,5,5},{4,5,2}};

void display()
{
	int i;
	for(i=0;i<edge;i++)
	{
		printf("%c%c -> %d\n",arr[i].v1+'A',arr[i].v2+'A',arr[i].wt);
	}
}

void bubble()
{
	int i,j;
    struct graph temp;
	for(i=0;i<edge-1;i++)
	{
		for(j=0;j<edge-1-i;j++)
		{
			if(arr[j].wt>arr[j+1].wt)
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int parent[100];

void makeset(int i)
{
	parent[i]=-1;
}

void simpleUnion(int i,int j)
{
	parent[i]=j;
}

int find(int i)
{
	while(parent[i]>=0)
	{
		i=parent[i];
	}
	return i;
}

int tree[100][2];
int cost=0;
int nth=0;

void kruskal()
{
	int i,j;
	bubble();
	for(i=0;i<edge;i++)
	{
		makeset(i);
	}
	for(i=0;i<edge;i++)
	{
		int u=find(arr[i].v1);
		int v=find(arr[i].v2);
		if(u!=v)
		{
			tree[nth][0]=arr[i].v1;
			tree[nth++][1]=arr[i].v2;
			simpleUnion(u,v);
			cost=cost+arr[i].wt;
		}
	}
}

void displayTree()
{
	int i;
	for(i=0;i<nth;i++)
	{
		printf("%c%c\t",tree[i][0]+'A',tree[i][1]+'A');
	}
	printf("\n");
}

int main()
{
	display();
	kruskal();
	displayTree();
	printf("Total cost=%d",cost);
	return 0;
}

/*output:
AB -> 7
BC -> 6
AD -> 8
DE -> 3
BD -> 3
DC -> 4
CE -> 2
CF -> 5
EF -> 2
CE      EF      DE      BD      AB
Total cost=17*/
