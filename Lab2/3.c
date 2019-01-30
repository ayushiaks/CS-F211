#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool colorgraph(int v, int g[v][v], int pos, int color[v], int c){
	
	if(color[pos]!=-1 && color[pos]!=c)
		return false;
	color[pos] = c;
	bool ans = true;
	for (int i = 0; i < v; ++i)
	{
		if(g[pos][i]){
			if(color[i]==-1)
				ans = ans & colorgraph(v, g, i, color, 1-c);
				// return true;
			if(color[i]!=-1 && color[i]!=1-c)
				return false;
	
		/* code */
		}
		if(!ans)
			return false;
	}
	return true;

}

bool isbipartite(int v, int g[v][v]){
	
	int color[v];
	for (int i = 0; i < v; ++i)
	{
		color[i] = -1;
		/* code */
	}

	return colorgraph(v, g, 0, color, 1);
}

int main(){
	int v, t;
	scanf("%d", &t);
	while(t--){
	scanf("%d", &v);
	int g[v][v];
	for (int i = 0; i < v; ++i)
	{
		for(int j = 0; j<v; j++)
			scanf("%d", &g[i][j]);
		/* code */
	}
	
	printf("%d\n", isbipartite(v, g));
}
}

/*
1  
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
yes
*/