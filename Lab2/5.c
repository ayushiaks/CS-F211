#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int g[10][10];
typedef struct node{
	int val;
	int f;
} node;

void dfs(int i, int v,  int visited[v], int vertex[v]){
	visited[i] = 1;
	vertex[i] = 1;
	
	for (int j = 0; j < v; ++j)
	{
		if(!visited[j] && g[i][j]==1)
			dfs(j, v, visited, vertex);
		/* code */
	}
}

void addEdge(int x, int y)
{
	g[x][y]=1;
	g[y][x]=1;
}

int main(){
	// int v, l, delta;
	// scanf("%d %d", &v, &delta);

	// int visited[v], count = 0;
	// for (int i = 0; i < v; ++i)
	// {
	// 	visited[i] = 0;		
	// 	/* code */
	// }
	// for (int i = 0; i < v; ++i)
	// {
	// 	for(int j = i+1; j < v; j++){
	// 		g[i][j] = 0;
	// 	}
	// }
	// for (int i = 0; i < v; ++i)
	// {
	// 	scanf("%d %d", &u[i].val, &u[i].f);
	// 	/* code */
	// }
	// for (int i = 0; i < v; ++i)
	// {
	// 	for(int j = i+1; j < v; j++){
	// 		if(abs(u[i].f-u[j].f)>=delta){
	// 			g[i][j] = 1, g[j][i] = 1;

	// 		}
	// 	}
	// 	/* code */
	// }
	int v =5;
	addEdge(1, 0);
	addEdge(2, 3);
	addEdge(3, 4);
	int matrix[v][v], visited[v], vertex[v];
	memset(vertex, 0, sizeof(vertex));
	memset(visited, 0, sizeof(vertex));
	for (int i = 0; i < v; ++i)
	{
		if(!visited[i])
		{
			dfs(i, v, visited, vertex);
			int matrix[v][v];
			for (int w = 0; w < v; ++w)
			{
				for(int j = 0; j < v; j++)
					matrix[w][j] = g[w][j];
				/* code */
			}
		
			printf("\n");
			for (int w = 0; w < v; ++w)
			{
				if(vertex[w]==0){
					for(int j = 0; j < v; j++){
						matrix[w][j] = -1, matrix[j][w] = -1;
					}
				}
				/* code */
			}
			for (int w = 0; w < v; ++w)
			{
				for(int j = 0; j < v; j++){
					if(matrix[w][j]!=-1)printf("%d ", matrix[w][j]);
				}
				printf("\n");
			}
			printf("**********\n");
			memset(vertex, 0, sizeof(vertex));

		}
		/* code */
	}

	// printf("%d\n", count);
}



