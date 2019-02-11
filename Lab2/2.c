

#include<stdio.h> 
  
// #define V 4 
  
#define INF 99999 
int max = 0;
void printpath(int v, int path[v][v], int i, int j){
	if(path[i][j]==i)
		return;
	printpath(v, path, i, path[i][j]);
	printf("%d ", path[i][j]);
}


   
void floydWarshall (int v, int g[v][v]) 
{ 
    int dist[v][v], i, j, k, path[v][v];
    for (int i = 0; i < v; ++i)
    {
    	for(int j = 0; j<v; j++)
    	{
    		if(g[i][j]!=INF)
    			path[i][j] = i;
            else if(i == j)
                path[i][j] = 0;
    		else
    			path[i][j] = -1;
    	}
    	/* code */
    }
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
                    	path[i][j] = path[k][j];
                    
                    }
            } 
        } 
    }
    max = dist[0][0];
    int u = 0, w = 0;
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if(dist[i][j]>max){
                max = dist[i][j];
              
            }
            /* code */
        }
        /* code */
    }
    //  for (int i = 0; i < v; ++i)
    // {
    //     for (int j = 0; j < v; ++j)
    //     {
    //         printf("%d ", dist[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
           if(dist[i][j]==max){
            printf("%d ", i);
            printpath(v, path, i, j);
            printf("%d ", j);
             printf("\n");
         }
        }
       
    }
    // printpath(v, path, 0, 5);
  
     // printpath(v, path, u, w);
     printf("\n%d\n", max);
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

   			if(g[i][j]==0 && i!=j)
   				g[i][j] = INF;
   		}
   		/* code */
   	}
    // Print the solution 
    floydWarshall(v, g); 
    
    return 0; 
} 

/*
4
0 1 0 0
0 0 1 0
1 0 0 1
0 1 0 0
*/