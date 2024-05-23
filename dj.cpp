#include<stdio.h>
#define INF 999
int w[100][100];
int n;

void readGraph(){
	FILE *fp;
	fp=fopen("Graph_Dijkstra.txt","r");
	if(fp==NULL) {
		printf("File open failed \n");
		return;
	}
	fscanf (fp,"%d",&n);
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			fscanf (fp,"%d",&w[i][j]);
		}
	}
	fclose(fp);
}

void showGraph(){
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			printf("%6d",w[i][j]);
		}
		printf("\n");
	}
}

int parent [100];
int mstset [100];
int key [100];

int minKey(){
	int min =INF;
	int index =-1;
	for (int i=0;i<n;i++) {
		if (mstset[i]==0) {
			if(key[i]<min){
				min = key[i];
				index=i;}
		}
	}
	return index;
}

void showPath(int v){
	if (parent[v]==-1){
		printf ("%3c",v+'A');
	return; }

	showPath (parent[v]);
	printf("%3c",v+'A');
}

void showPathCost (int v){

	printf ("\n Path cost = %d\n", key[v]);
	return;
}


void Dijkstra(int v)
{
	for(int i =0; i<n;i++)
	{
		parent[i]=-1 ;
		mstset[i]=0;
		key[i]=INF;
	}
	key[v]=0;
	for (int i= 0;i <n;i++) 
	{
		int u = minKey();
		mstset[u]=1;
		for(v=0; v<n; v++)
		{
			if(w[u][v]!=0 && w[u][v]!=INF)
			{
				if(mstset[v]==0)
				{
					if(key[v]>w[u][v] + key[u])
					{
						parent[v] =u;
						key[v]=w[u][v]+key[u]; 
					}
				}
			}
		}
	}
}

int main() 
{
	readGraph();
	showGraph();
	Dijkstra(0);
	for(int i=1;i<n;i++){
		showPath (i);
		showPathCost(i);
	}
	return 0;
}
/* 0     5   999     6   999   999
     5     0     2     2   999   999
   999     2     0     1     4     6
     6     2     1     0     3   999
   999   999     4     3     0     1
   999   999     6   999     1     0
  A  B
 Path cost = 5
  A  B  C
 Path cost = 7
  A  D
 Path cost = 6
  A  D  E
 Path cost = 9
  A  D  E  F
 Path cost = 10*/
