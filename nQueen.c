#include <stdio.h>
#include<math.h>
int x[20],count=1;

void print(int n)
{
	int i,j;
	printf("\n\nSolution %d:\n\n",count++);
	for(i=1;i<=n;i++)
	{
		printf("\t%d",i);
	}
	for(i=1;i<=n;i++)
	{
		printf("\n\n%d",i);
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)
				printf("\tQ");
			else
				printf("\t-");
		}
	}
}

int place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if(x[j]==i)
			return 0;
		else
			if(abs(j-k)==abs(x[j]-i))
				return 0;
	}
	return 1;
}

void queen(int k,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			
			if(k==n)
				print(n);
			else
				queen(k+1,n);
		}
	}	
}

int main()
{
	int n;
	printf("The no. of queen:");
	scanf("%d",&n);
	queen(1,n);
	return 0;
}
/*The no. of queen:4


Solution 1:

        1       2       3       4

1       -       Q       -       -

2       -       -       -       Q

3       Q       -       -       -

4       -       -       Q       -

Solution 2:

        1       2       3       4

1       -       -       Q       -

2       Q       -       -       -

3       -       -       -       Q

4       -       Q       -       -*/
