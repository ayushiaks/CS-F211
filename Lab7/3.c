#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define p3(x, y, z) printf("%d %d %d\n", x, y, z);

int ans[100], final, g[100][100], vis[100], n, f[100];

void dfs(int i){
	vis[i] = 1;
	int leaf = 1;
	for (int j = 1; j <= n; ++j)
	{
		if(!vis[j] && g[i][j]){
			leaf=0;
			dfs(j);
		}
	
	}
	if(leaf)
	final = i;
}

int main(){
	int count=0, root = 1, comp = 0;
	s(n)
	int arr[n];
	for (int i = 1; i <= n; ++i)
	{
		s(arr[i])
		if(arr[i]==i){
			ans[i] = 1;
			if(count == 0){
			root = i;
			count++;
		}
		}
		g[i][arr[i]] = 1;
		g[arr[i]][i] = 1;
		
		/* code */
	}
	// p(root)
	count = 0;
	for (int i = 1; i <= n; ++i)
	{

		if(!vis[i]){
			
			if(arr[final]!=root && final!=0){
				count++;

				arr[final] = root;
			}
			dfs(i);
			comp++;
		}
		
		

	}
	// p()
	if(arr[final]!=root && final!=0 && comp!=1){
		count++;
		// p(final)
		arr[final] = root;
	}
	p(count)
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", (arr[i]));
		/* code */
	}
	printf("\n");
	// p(count)

}


/*
7
4 3 2 6 3 5 2
ans : 1
4 3 3 6 3 5 2
*/