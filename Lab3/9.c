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
	int check = 0;
	for (int i = 1; i <= n; ++i)
	{
		memset(visited, 0, sizeof(visited));
		dfs(i);
		int ans = 1;
		for (int j = 1; j <= n; ++j)
		{
			if(visited[j]==0)
			{
				ans = 0;
				// check = 0;
			}
			/* code */
		}
		if(ans == 1)
			{
				printf("%d, ", i);
				if(check==0)
					check = 1;
			}
		/* code */
	}
	if (check==1)
	{
		printf("Yes\n");
		/* code */
	}
	else
		printf("No\n");
}