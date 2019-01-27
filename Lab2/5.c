#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int val;
	int f;
} node;

void dfs(int i, int v, int visited[v], int g[v][v]){
	visited[i] = 1;
	for (int j = 0; j < v; ++j)
	{
		if(!visited[j] && g[i][j]==1)
			dfs(j, v, visited, g);
		/* code */
	}
}

int main(){
	int v, l, delta;
	scanf("%d %d", &v, &delta);
	node u[v];
	int g[v][v], visited[v], count = 0;
	for (int i = 0; i < v; ++i)
	{
		visited[i] = 0;		
		/* code */
	}
	for (int i = 0; i < v; ++i)
	{
		for(int j = i+1; j < v; j++){
			g[i][j] = 0;
		}
	}
	for (int i = 0; i < v; ++i)
	{
		scanf("%d %d", &u[i].val, &u[i].f);
		/* code */
	}
	for (int i = 0; i < v; ++i)
	{
		for(int j = i+1; j < v; j++){
			if(abs(u[i].f-u[j].f)>=delta){
				g[i][j] = 1;

			}
		}
		/* code */
	}
	for (int i = 0; i < v; ++i)
	{
		if(!visited[i])
		{
			dfs(i, v, visited, g);
			count++;
		}
		/* code */
	}
	printf("%d\n", count);
}



