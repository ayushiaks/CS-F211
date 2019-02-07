#include<stdio.h>
#include<string.h>
#define max(a, b) (a>b?a:b)

int g[100][100], visited[100][100], n;

int area(int i, int j){
	if(i<0 || i>=n || j<0|| j>=n || visited[i][j] || !g[i][j])
		return 0;
	visited[i][j] = 1;
	return (1+area(i-1, j)+area(i+1, j)+area(i, j-1)+area(i, j+1)+area(i+1, j+1)+area(i-1, j-1)+area(i+1, j-1)+area(i-1, j+1));

}


int main(){
	int ans = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j){
			scanf("%d", &g[i][j]);
		}
		/* code */
	}
			
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j){
			// printf("%d\n", area(i, j));
			int t = area(i,j);
			if(ans<t)
				ans = t;
		}
			
	}

	printf("%d\n", ans);
}