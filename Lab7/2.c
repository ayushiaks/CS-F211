#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int adj[100][100];
int v,e;
int cost[100];
bool visited[100];
int path[100];
bool protect[100];
int len=0;
int colour[100]={0};
int col=1;

void init()
{
	for(int i=0;i<=v;i++)
		visited[i]=false;
}

void is_reachable(int s)
{
	visited[s]=true;
	for(int i=1;i<=v;i++)
	{
		if(adj[s][i]==1 && !visited[i])
			is_reachable(i);
	}
}

int main()
{
	scanf("%d",&v);

	for(int i=1;i<=v;i++)
		scanf(" %d",&cost[i]);

	scanf("%d",&e);

	while(e--)
	{
		int a,b;
		scanf(" %d %d",&a,&b);
		adj[a][b]=1;
	}

	bool flag1, flag2;
	for(int i=1;i<=v;i++)
	{
		if(!colour[i])
		{
			for(int j=1;j<=v;j++)
			{
				flag1=true; flag2=true;
				init();
				is_reachable(i);
				if(!visited[j])
					flag1=false;
				init();
				is_reachable(j);
				if(!visited[i])
					flag1=false;
				if(flag1 && flag2 && !colour[j])
					colour[j]=col;
			}
			col++;
		}
	}
	for(int i=1;i<=v;i++)
		printf("%d ",colour[i]);
	printf("\n");

	int total=0;
	int ways=1;

	// printf("Max colour is %d\n",col);

	for(int i=1;i<col;i++)
	{
		int min = INT_MAX;
		int temp=0;
		for(int j=1;j<=v;j++)
		{
			if(colour[j]==i && cost[j]<min)
				min=cost[j];
		}
		for(int j=1;j<=v;j++)
		{
			if(colour[j]==i && cost[j]==min)
				temp++;
		}
		total=total+min;
		ways=ways*temp;
	}

	printf("%d %d\n",total,ways);
	return 0;
}
