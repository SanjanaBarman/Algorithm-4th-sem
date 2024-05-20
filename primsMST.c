#include<stdio.h>
#define INF 999

int n,w[100][100];

void readGraph()
{
	int i,j;
	FILE *fp;
	fp=fopen("prims.txt","r");
	if(fp==NULL)
	{
		printf("File cannt open\n");
		return;
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%d",&w[i][j]);
		}
	}
	fclose(fp);
}

void showGraph()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%6d",w[i][j]);
		}
		printf("\n");
	}
}

int parent[100];
int mstSet[100];
int key[100];

int minkey()
{
	int min=INF;
	int index=-1;
	int i;
	
	for(i=0;i<n;i++)
	{
		if(mstSet[i]==0)
		{
			if(key[i]<min)
			{
				min=key[i];
				index=i;
			}
		}
	}
	return index;
}

void prims(int v)
{
	int i;
	for(i=0;i<n;i++)
	{
		parent[i]=-1;
		mstSet[i]=0;
		key[i]=INF;
	}
	key[v]=0;
	for(i=0;i<n;i++)
	{
		int u;
		u=minkey();
		mstSet[u]=1;
		for(v=0;v<n;v++)
		{
			if(w[u][v]!=0&&w[u][v]!=INF)
			{
				if(mstSet[v]==0)
				{
					if(key[v]>w[u][v])
					{
						parent[v]=u;
						key[v]=w[u][v];
					}
				}
			}
		}
	}
}

void print(int v)
{
	int i;
	int cost=0;
	for(i=0;i<n;i++)
	{
		cost=cost+key[i];
		if(i!=v)
		{
			printf("(%c,%c)\t",parent[i]+'A',i+'A');
		}
	}
	printf("\nTotal cost=%d",cost);
}

int main()
{
	readGraph();
	showGraph();
	prims(0);
	print(0);
	return 0;
}

/*  output
  	0     5   999     6   999   999
     5     0     2     2   999   999
   999     2     0     1     4     6
     6     2     1     0     3   999
   999   999     4     3     0     1
   999   999     6   999     1     0
(A,B)   (B,C)   (C,D)   (D,E)   (E,F)
Total cost=12
*/
