#include<stdio.h>
#include<limits.h>


int mindistance(int v, int dist[v], int visited[v]){
	int min = INT_MAX, index;
	for (int i = 0; i < v; ++i)
	{
		if(dist[i]<=min && visited[i]==0)
			min = dist[i], index = i;
		/* code */
	}
	return index;
}

void printdist(int v, int dist[v]){
	for (int i = 0; i < v; ++i)
	{
		printf("%d %d\n", i, dist[i]);
		/* code */
	}
}

void dijsktra(int v, int g[v][v]){
	int dist[v], visited[v];
	for (int i = 0; i < v; ++i)
	{
		dist[i] = INT_MAX, visited[i] = 0;
		/* code */
	}
	dist[0] = 0;
	for (int i = 0; i < v-1; ++i)
	{
		int u = mindistance(v, dist, visited);
		visited[u] = 1;
		
		for (int w = 0; w < v; ++w)
		{
		if(visited[w]==0 && g[u][w]>0 && dist[u]!=INT_MAX && dist[u]+g[u][w]<dist[w])
			{
				dist[w] = dist[u]+g[u][w];
				printf("%d\n", w);
			}
		/* code */
	}
	
	// return;
}
printdist(v, dist);
}

int main(){
	int v;
	scanf("%d", &v);
	int g[v][v];
	for (int i = 0; i < v; ++i)
	{
		for(int j = 0; j<v; j++)
			scanf("%d", &g[i][j]);
		/* code */
	}
	dijsktra(v, g);
}
int main(){

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


*/