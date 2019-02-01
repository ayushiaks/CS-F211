#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n, g[1000][1000], visited[1000];

void dfs(int i){
	visited[i]=1;
	for(int j = 1;j<= n; j++){
		if(!visited[j] && g[i][j])
			dfs(j);
	}
}

int main(){
	int m, a, b, t;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &a, &b);
		g[a][b] = 1;
		/* code */
	}
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		memset(visited, 0, sizeof(visited));
		dfs(a);
		if(visited[b]==1)
			printf("Yes\n");
		else
			printf("No\n");
		/* code */
	
}
}