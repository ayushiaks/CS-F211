

#include<stdio.h> 
  
#define V 4 
  
#define INF 99999 
  
typedef struct cycle{
	int n;
	int w;
	int list[];
	 
} cycle;

void printSolution(int v, int dist[v][v]); 
  
void floydWarshall (int v, int g[v][v]) 
{ 
    int dist[v][v], i, j, k; 
  	cycle c[v];
     for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = g[i][j]; 
  
     for (k = 0; k < V; k++) 
    { 
         for (i = 0; i < V; i++) 
        { 
        	c[i].w = 0;
            for (j = 0; j < V; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    {
                    	dist[i][j] = dist[i][k] + dist[k][j]; 
                    	c[i].n = i;
                    	c[i].list[c[i].w] = k;
                    	c[i].w++;
                    }
            } 
        } 
    }

    // for (int i = 0; i < v; ++i)
    //  {
    //  	if (dist[i][i]!=INF){
    //  		printf("%d ", c[i].n);
    //  		for(int j = 0; j < c[i].w; j++){
    //  			printf("%d ", c[i].list[j]);
    //  		}
    //  		printf("%d\n", c[i].n);
    //  	}
    //  } 

  
     printSolution(v, dist); 
} 
  
void printSolution(int v, int dist[v][v]) 
{ 
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n"); 
    for (int i = 0; i < v; i++) 
    { 
        for (int j = 0; j < v; j++) 
        { 
            if (dist[i][j] == INF) 
                printf("%7s", "INF"); 
            else
                printf ("%7d", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 
  
int main() 
{ 
	int v;
	scanf("%d", &v);
    int g[v][v];
    for (int i = 0; i < v; ++i)
    {
    	for(int j = 0; j<v; j++)
    		scanf("%d", &g[i][j]);
    	/* code */
    }
   	for (int i = 0; i < v; ++i)
   	{
   		for(int j = 0; j<v; j++)
   		{
   			if(g[i][j]==0)
   				g[i][j] = INF;
   		}
   		/* code */
   	}
    // Print the solution 
    floydWarshall(v, g); 
    
    return 0; 
} 
