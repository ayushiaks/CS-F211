#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define max(a, b)(a>b?a:b)
#define s(x) scanf("%llu", &x);
#define p(x) printf("%llu\n", x);
#define int unsigned long long int

int dist[100][100], g[100][100], n;

void floydWarshall(){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(j!=i && g[i][j]==0){
				// printf("%d %d\n", i, j);
				dist[i][j] = INT_MAX;
			}
			else
				dist[i][j] = g[i][j];
			/* code */
		}
		/* code */
	}
	
	for(int k = 0; k < n; k++){
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j] = dist[i][k]+dist[k][j];
					// printf("%d %d %d %d %d %d\n",dist[i][k], dist[k][j], i, j, k, dist[i][j]);
				}
				/* code */
			}
			/* code */
		}
	}
	
}

int main(){
	int m, a, b, c;
	s(n)
	s(m)
	for (int i = 0; i < m; ++i)
	{		
		s(a)
		s(b)
		s(c)
		g[a][b] = c;
		/* code */
	}
	floydWarshall();
	
	int t;
	s(t)
	while(t--){
		s(a) s(b) s(c)
		if(c==0)
			p(g[a][b])
		else
			p(dist[a][b])
	}
}