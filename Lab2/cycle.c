#include<stdio.h>
#include<stdbool.h>

int cycleutil(int i, int v, bool visited[v], bool track[v], int g[v][v], int color[v]){
	int count = 0;
	if(visited[i] == false){
		visited[i] = true;
		track[i] = true;
		color[i] = 1;
		int counter = 0;
		for (int j = 0; j < v; ++j)
		{
			if(visited[j]==false && g[i][j] && cycleutil(j, v, visited, track, g, color))
				{
					color[j] = 1, count++;
					// track[i] = false;
					counter = 1;
					
				}
			else if(track[j] && g[i][j])
				{
					color[j] = 1, count++;
					// track[i] = foralse;
					counter = 1;
					}
			if(counter == 1){
				for (int j = 0; j < v; ++j)
					{
						if(color[j] == 1)
							printf("%d ", j);
						/* code */
					}
					printf("\n");
				for (int j = 0; j < v; ++j)
				{
					if(j!=i)
						color[j] = 0, track[j] = false;
					/* code */
				}
				counter = 0;
			}
			/* code */
		}

	}
	
	track[i] = false;
	return count;
}


void cycle(int v, int g[v][v]){
	bool visited[v], track[v];
	int  color[v], counter = 0;
	for (int i = 0; i < v; ++i)
	{
		visited[i] = false, track[i] = false;
		/* code */
	}

	for (int i = 0; i < v; ++i)
	{
		// count = 0;
		for (int j = 0; j < v; ++j)
		{
			color[j] = 0;
			/* code */
		}
		int count = cycleutil(i, v, visited, track, g, color);
		// printf("%d\n", count);
		if (count>0)
			{
				
				// printf("cycle\n");
				
				counter = 1;
			}
		

	}
	if(counter == 0)
		printf("No cycle present\n");
	return;

}

int main(){
	int n, e;
	scanf("%d %d", &n, &e);
	int g[n][n];
	int t, a, b, count = 0;
	// scanf("%d", &t);
	for (int i = 0; i < n; ++i)
	{
		for(int j= 0; j<n; j++){
			g[i][j] = 0;
		}
		/* code */
	}
	while(e--){
		scanf("%d %d", &a, &b);
		// printf("%d %d\n", a,b);
		g[a][b] = 1;
	}
	cycle(n, g);
}
/*
4
6
0 1
0 2
1 2
2 0
2 3
3 3


5
8
0 1
1 2
1 3
1 4
2 1
2 3
3 0
3 2
01230 0130 121 1321 232
	*/