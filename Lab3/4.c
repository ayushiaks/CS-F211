#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 99999
int visited[100], flag, count, x, y, v, g[100][100], check[100][100];

void dfs(int i, int j){
	
	if(i==j)
		return;
	visited[i]=1;
	if(check[i][j]==0){
		count++;
		printf("plus %d %d\n", i, j);
		if(i==x){
		flag = 1;
		}
		if(j==y && flag==1){
			printf("minus %d %d\n", i, j);
			count--;
			flag = 0;
		}
	}
	check[i][j] = 1;
	for(int w = i+1;w<= v; w++){
		if(!visited[w] && g[i][w] )
			{
				dfs(w, j);
			}

	}
}

 int main(){
 	int a, b;
 	scanf("%d %d %d", &v, &x, &y);
 	for (int i = 1; i <= v-1; ++i)
 	{
 		scanf("%d %d", &a, &b);
 		g[a][b] = 1;
 		g[b][a] = 1;
 		/* code */
 	}
 	
 	for (int i = 1; i <= v; ++i)
 	{
 		// count--;
 		for(int j = 1; j<=v;j++){
 		if(i!=j){
 			
 			dfs(i, j);
 		}
 		/* code */
 		
 	}
 	memset(visited, 0, sizeof(visited));
 	}
 	printf("%d\n", count);
 }


