#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// int gdash[10][10];
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

// void addedge(int x, int y){
// 	gdash[x][y] = gdash[y][x] = 1;
	// gdash[x][x] = 1, gdash[y][y] = 1;
// }


int main(){

	int v;
	scanf("%d", &v);
	int g[v][v], edge = 0;
	for (int i = 0; i < v; ++i)
	{
		for(int j = 0; j< v; j++)
			{
				scanf("%d", &g[i][j]);
				g[i][j]--;
				
			}
		/* code */
	}
	for (int i = 0; i < v; ++i)
	{
		for(int j = 0; j< v; j++)
			{
				if(g[i][j]!=-1 && g[j][i]==0) {
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
				if(row!=-1){
					for(int w = 0; w < v; w++){
						int col = g[j][w];
						if(col!=-1 && col!=row)
							{
								gdash[row][col] = 1;
							}
					}
				}

			}
		/* code */
	}
	for (int i = 0; i < edge; ++i)
	{
		for(int j = 0; j< edge; j++){
			printf("%d ", gdash[i][j]);
		}
		printf("\n");

		/* code */
	}
	// int edge = 5;
	// addedge(1, 0);
	// addedge(1, 2);
	// addedge(2, 0);
	// addedge(0, 3);
	// addedge(3, 4);
	// for (int w = 0; w < edge; ++w)
	// 	{
	// 		for(int j = 0; j < edge; j++){
	// 			printf("%d ", gdash[w][j]);
	// 		}
	// 		printf("\n");
	// 	}				
	int vertex[edge], ans = 0;
	memset(vertex, 0, sizeof(vertex));
	for (int i = 0; i < edge; ++i)
	{
		int visited[edge], count = 0;
		memset(visited, 0, sizeof(visited));
		
		printf("remove vertex %d\n", i);
		for (int j = 0; j < edge; ++j)
		{	

				if(!visited[j] && i!=j) 	
				{
					int matrix[edge][edge], p=0;
					for (int w = 0; w < edge; ++w)
						{
							for(int j = 0; j < edge; j++)
							matrix[w][j] = gdash[w][j], matrix[i][j] = matrix[j][i] = -1;
								/* code */
						}
					dfs(j, edge, visited, matrix, vertex);
					count++;
					vertex[i] = 0;
				           
					for (int w = 0; w < edge; ++w)
					{
						if(vertex[w]==0){
							for(int j = 0; j < edge; j++){
								matrix[w][j] = -1, matrix[j][w] = -1;
							}
						}
						/* code */
					}
					// printf("%d\n", j);
					// for (int w = 0; w < edge; ++w)
					// 	printf("%d ", vertex[w]);
					for (int w = 0; w < edge; ++w)
					{
						for(int j = 0; j < edge; j++){
							if(matrix[w][j]!=-1) printf("%d ", matrix[w][j]);
							// else printf("%d ", 0);
							if(matrix[w][j]==1) p =1;
						}
						printf("\n");
					}
					// break;
					if(p==0)
						count--;
					 printf("********\n");
					memset(vertex, 0, sizeof(vertex));

			}
			
			
		}
		if(count>=2)
				ans = 1;
		
}
if(ans == 0)
			printf("none\n");


printf("%d\n", edge-1);
}

/*



4
0 1 1 1
1 0 0 1
1 0 0 1
1 1 1 0


*/
