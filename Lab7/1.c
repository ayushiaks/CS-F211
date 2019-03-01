#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);

int alice[100], bob[100], n, x, ans, tree[100][100], vis[100];

void dfs(int v, int p, int  *dist, int h){
	dist[v] = h;
	vis[v]  = 1;
	for(int i = 0 ; i < n; i++){
		if(i != p && !vis[i] && tree[v][i]){
			// p(i)
			dfs(i, v, dist, h+1);
		}
	}
}

int main(){
	s(n) s(x)
	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		s(u) s(v)
		tree[u-1][v-1] = 1, tree[v-1][u-1] = 1;
		/* code */
	}
	
	dfs(0, 0, alice, 0);
	dfs(x-1, x-1, bob, 0);
	for (int i = 0; i < n; ++i)
	{
		if(alice[i]>bob[i])
			ans = max(ans, alice[i]);
		/* code */
	}
	p(2*ans)
}