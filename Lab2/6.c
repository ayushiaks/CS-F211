#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void dfs(int i, int v, int visited[v], int g[v][v], int vertex[v]){
	visited[i] = 1;
	vertex[i] = 1;
	for (int j = 0; j < v; ++j)
	{
		if(!visited[j] && g[i][j]==1)
			dfs(j, v, visited, g, vertex);
		/* code */
	}
}



int main(){

	int v;
	scanf("%d", &v);
	int g[v][v], edge = 1;
	for (int i = 0; i < v; ++i)
	{
		for(int j = 0; j< v; j++)
			{
				scanf("%d", &g[i][j]);
				
			}
		/* code */
	}
	for (int i = 0; i < v; ++i)
	{
		for(int j = 0; j< v; j++)
			{
				if(g[i][j]!=0 && g[j][i]==1) {
					g[i][j] = ++edge, g[j][i] = edge;
					
				}

			}

		}
		edge++;
	
	int gdash[edge][edge];
	
	memset(gdash,0,sizeof(gdash));
	for (int i = 0; i < v; ++i)
	{
		for(int j = 0; j< v; j++)
			{
				int row = g[i][j];
				if(row!=0){
					for(int w = 0; w < v; w++){
						int col = g[j][w];
						if(col!=0 && col!=row)
							{
								gdash[row][col] = 1;
								if(row == 1){
									printf("row %d %d\n", i, j);
								}
								if(col == 1)
									printf("col %d %d\n", j, w);
							}
					}
				}

			}
		/* code */
	}
	for (int i = 2; i < edge; ++i)
	{
		for(int j = 2; j< edge; j++){
			printf("%d ", gdash[i][j]);
		}
		printf("\n");

		/* code */
	}
	int vertex[v];
	memset(vertex, 0, sizeof(vertex));
	for (int i = 2; i < edge; ++i)
	{
		int w = 0, temp[edge-2], visited[edge-2], count = 0;
		memset(visited, 0, sizeof(visited));
		int matrix[v][v];
		for (int w = 0; w < v; ++w)
			{
				for(int j = 0; j < v; j++)
				matrix[w][j] = gdash[w][j], matrix[i][j] = matrix[j][i] = -1;
					/* code */
			}
		
		for (int j = 2; j < edge; ++j)
		{
			if(!visited[j])
			{
				dfs(j, v, visited, gdash, vertex);
				count++;
			}
		
		if(count>=2){
				printf("%d\n", i);
				
			
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
				break;
		
		}

		memset(vertex, 0, sizeof(vertex));
	}
	
}
}

/*
4
0 1 1 1
1 0 0 1
1 0 0 1
1 1 1 0


*/
