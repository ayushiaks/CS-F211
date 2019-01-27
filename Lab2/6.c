#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void dfs(int i, int v, int visited[v], int g[v][v]){
	visited[i] = 1;
	
	for (int j = 0; j < v; ++j)
	{
		if(!visited[j] && g[i][j]==1)
			dfs(j, v, visited, g);
		/* code */
	}
}

void dfsprint(int i, int v, int visited[v], int g[v][v]){
	visited[i] = 1;
	printf("%d ", i);
	for (int j = 0; j < v; ++j)
	{
		if(!visited[j] && g[i][j]==1)
			{
				dfs(j, v, visited, g);
				printf("\n");
			}
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

	for (int i = 2; i < edge; ++i)
	{
		int w = 0, temp[edge-2], visited[edge-2], count = 0;
		memset(visited, 0, sizeof(visited));
		for(int j = 2; j< edge; j++)
			{
				temp[w++] = gdash[i][j];
				gdash[i][j] = 0, gdash[j][i] = 0;	

			}
		for (int j = 2; j < edge; ++j)
		{
			if(!visited[j])
			{
				dfs(j, v, visited, gdash);
				count++;
			}
		}
		if(count>=2){
			printf("%d\n\n", i);
			memset(visited, 0, sizeof(visited));
			for (int j = 2; j < edge; ++j)
			{
				
				if(!visited[j])
				{
					dfsprint(j, v, visited, gdash);
					
				}
				// printf("\n");
			}
		w=0;
		for (int j = 2; j < edge; ++j)
		{
			gdash[i][j] = temp[w], gdash[j][i] = temp[w++];
			/* code */
		}
	}
	printf("%d\n", edge-2);


}
}

/*
4
0 1 1 1
1 0 0 1
1 0 0 1
1 1 1 0


*/