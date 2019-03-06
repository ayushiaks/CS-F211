#include<stdio.h> 

#define INF 99999 
#define min(a, b) (a<b?a:b)
#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
 
int n, m, s, t, graph[1001][1001], dist[1001][1001], count;

void printSolution(); 
  
void floydWarshall () 
{ 
    int i, j, k; 
  
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++){
        	if(i==j)
        		dist[i][j] = 0;
        	else if(graph[i][j]==0)
        		dist[i][j]=INF;
        	else
            dist[i][j] = graph[i][j]; 
        }
  
  
      for (k = 0; k < n; k++) 
    { 
          for (i = 0; i < n; i++) 
        { 
              for (j = 0; j < n; j++) 
            { 
              if (dist[i][k] + dist[k][j] < dist[i][j]) {
              		// printf("here\n");
                    dist[i][j] = dist[i][k] + dist[k][j]; 
              }
            } 
        } 
    } 
  
    
   
} 
  

int main() 
{ 
    s(n) s(m) s(s) s(t)

    for (int i = 0; i < m; ++i)
    {
    	int a, b;
    	s(a) s(b)
    	graph[a-1][b-1] = 1;
    	graph[b-1][a-1] = 1;
    	/* code */
    }
    floydWarshall();
    int d = dist[s-1][t-1];
    // p(d)
   
    for (int i = 0; i < n; ++i)
    {
    	for (int j = i; j < n; ++j)
    	{
    		if(graph[i][j]==0 && i!=j){
    			// p2(i, j)
    			graph[i][j] = 1;
    			floydWarshall();
    			
    			if(d<=dist[s-1][t-1]){
    				// p2(i, j)
    				// p(dist[s-1][t-1])
    				count++;
    			}
    			graph[i][j]= 0;

    		}
    		// if(dist[s-1][i]+1+dist[j][t-1]>=dist[s-1][t-1] && dist[s-1][j]+1+dist[i][t-1]>=dist[s-1][t-1]){
    		// 		count++;
    		// 	}
    		/* code */
    	}
   
    }
    
    p(count)
    return 0; 
} 

/*
5 6 1 5
1 2
1 3
1 4
4 5
3 5
2 5
ans:3
*/