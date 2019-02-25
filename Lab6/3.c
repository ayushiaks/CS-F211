#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define p3(x, y, z) printf("%d %d %d\n", x, y, z);

int v, k, g[10][10], cat_count, count, visited[10], cat[10], m;
typedef struct node{
	int val;
	int f;
} node;

void dfs(int i){
	visited[i] = 1;
	if(cat[i] && i!=1)
		cat_count++;
	
	int flag = 0;
	for (int j = 0; j <= v; ++j)
	{
		
		if(!visited[j] && g[i][j]==1)
			{
				flag = 1;
				// p2(56, j)
				dfs(j);
				// p3(i, j, cat_count)
				if(cat_count<=m){	
						// p(j)
						count++;
					}
				if(i==1)
					cat_count = k;
			}
				

	}
	
	
		
}

void addEdge(int x, int y)
{
	g[x][y]=1;
	// g[y][x]=1;
}

int main(){
	m=1;
	v =5;
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(3, 4);
	addEdge(1, 5);
	cat[1] = 1, cat[2] = 1;
	k = cat[1];
	cat_count = k;
	for (int i = 1; i <= v; ++i)
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	p(count)
	
}



