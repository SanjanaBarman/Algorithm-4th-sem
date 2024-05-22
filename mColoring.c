#include<stdio.h>
#include<stdbool.h>
#define n 4

int m=2;
int x[n];
int G[n][n];

void nextValue(int k)
{
	int j;
	while(1)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=1;j<=k-1;j++)
		{
			if(G[j][k]==1 && x[j]==x[k])
			{	
				break;
			}
		}
		if(j==k)
			return;
	}
	
}

void mCol(int k)
{
	int i;
	while(1)
	{
	
		nextValue(k);
		if(x[k]==0)
			return;
		if(k==n)
		{
			printf("All possible slotutions:");
			for(i=1;i<=n;i++)
			{
				printf("%d\t",x[i]);
			}
			printf("\n");	
		}
		else
			mCol(k+1);
	}
}

int main()
{
	int i,j;
	printf("Enter the graph matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
	mCol(1);
	return 0;
}

/*OUTPUT:-----
Enter the graph matrix:
0       1       0       1
1       0       1       0
0       1       0       1
1       0       1       0
All possible slotutions:1       2       1       2
All possible slotutions:2       1       2       1
*/

