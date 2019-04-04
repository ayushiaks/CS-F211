#include <stdio.h>
#include <limits.h>

int grid[1000][1000];
int dp[1000][1000];
int n;

int dirleft[]={0,-1,0,1};
int dirright[]={-1,0,1,0};

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void helper(int x, int y, int curr)
{
	if(x<0 || x>=n || y<0 || y>=n || max(curr,grid[x][y])>=dp[x][y])
		return;
	dp[x][y]=max(curr,grid[x][y]);
	for(int i=0;i<4;i++)
	{
		helper(x+dirleft[i],y+dirright[i],dp[x][y]);
	}
}


int swim()
{
	helper(0,0,grid[0][0]);
	return dp[n-1][n-1];
}



int main()
{
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf(" %d",&grid[i][j]);
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=INT_MAX;
		}
	}

	printf("%d\n",swim());
	return 0;
}