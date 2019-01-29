#include <stdio.h>
#define max(a, b) (a>b?a:b)

int n,e,t,matrix[100][100]={{0}}, check[100]={0}, visited[100] = {0}, tmp = 0;

void dfs(int node, int count, int origin)
{
	if(visited[node] == 1)
		return;
	visited[node] = 1;
	// printf("node %d\n", node);
	if(count == t)
	{
		printf("count: %d, t: %d\n", count, t);
		printf("checked %d, %d\n", origin, node);
		tmp++;
		check[node] = 1;
		check[origin] = 1;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(matrix[node][i]==1 && count <= t)
		{
			dfs(i, count+1, origin);
		}
	}
	printf("\n");
}

int main()
{
	int i,j,k,e,u,v;
	scanf("%d %d", &n, &e);
	int maxi = 0;
	for(i=0;i<e;i++)
	{
		scanf("%d %d", &u, &v);
		maxi = max(maxi, max(u, v));
		matrix[u][v] = matrix[v][u] = 1;
	}
	scanf("%d", &t);
	n = maxi+1;
	for(i=0;i<n;i++)
	{
		printf("visiting %d\n", i);
		dfs(i,0,i);
		for(j=0;j<n;j++)
			visited[j]=0;
	}
	int c=0;
	for(i=0;i<n;i++)
	{
		if(check[i] == 1)
			c++;
	}
	printf("%d\n", tmp/2);
	return 0;
}

/*
6
5
1 2
1 3
2 4
2 5
3 8
2

5
4
0 1
1 2
2 3
1 4
2
*/