#include<stdio.h>
#include<limits.h>



int floydWarshall (int v, int g[v][v], int uni[v]) 
{ 
    int dist[v][v], i, j, k;
   
     for (i = 0; i < v; i++) 
        for (j = 0; j < v; j++) 
            dist[i][j] = g[i][j]; 
  
     for (k = 0; k < v; k++) 
    { 
         for (i = 0; i < v; i++) 
        { 
        	
            for (j = 0; j < v; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    {
                    	dist[i][j] = dist[i][k] + dist[k][j]; 
                    	
                    
                    }
            } 
        } 
    }

	int min = INT_MAX, in;
	// printdist(v, dist);
	for (int i = 0; i < v; ++i)
		{
			if(dist[0][i]<min && uni[i] == 1)
				min = dist[0][i], in =i;
			if(dist[0][i] = min && i<in && uni[i] == 1)
				in = i;

			/* code */
		}

return in;
}

int main(){
	int v, m, a, b;
	scanf("%d", &v);
	int g[v][v];
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			g[i][j] = 0;
			/* code */
		}
		// printf("\n");
		/* code */
	}
	for (int i = 0; i < v-1; ++i)
	{
		
			scanf("%d %d", &a, &b);
			g[a][b] = 1;
			g[b][a] = 1;
			
			
	}

	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			printf("%d ", g[i][j]);
			/* code */
		}
		printf("\n");
		/* code */
	}
	scanf("%d", &m);
	int uni[v];
	for (int i = 0; i < v; ++i)
	{
		uni[i] = 0;
		/* code */
	}

	for (int i = 0; i < m; ++i)
	{
		int a;
		scanf("%d", &a);
		uni[a] = 1;
		/* code */
	}
	for (int i = 0; i < v; ++i)
	{
		// printf("%d", uni[i]);
		/* code */
	}
	
	printf("%d\n", floydWarshall(v, g, uni));
}

/*
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0 
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0

6
0 1
1 2
1 3
3 4
4 5
2
3
5
*/