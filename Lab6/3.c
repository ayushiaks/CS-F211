#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define p3(x, y, z) printf("%d %d %d\n", x, y, z);

int v, k, g[10][10], cat_count, count, visited[10], cat[10], m;
typedef struct node{
	int val;
	int f;
} node;

void dfs(int i, int flag){
	visited[i] = 1;
	if(cat[i] && i!=1){
		cat_count++;
		// printf("if %d %d\n", i, cat_count);
	}
	else{
		// printf("else %d\n", i);
		cat_count = k;
	}
	if(cat_count==m){
		// p(i)
		flag = 1;
	}
	int leaf = 1;
	for (int j = 0; j <= v; ++j)
	{
		
		if(!visited[j] && g[i][j]==1)
			{
				leaf = 0;
				// p2(j, flag)
				dfs(j, flag);
			
				if(i==1){
					cat_count = k;
				}
			}
				

	}
	if(cat_count<=m && leaf == 1 && flag == 0)
	{	
		p(i)
		count++;

	}
	
	
		
}


int main(){
	s(v)
	s(m)
	for (int i = 1; i <= v; ++i)
	{
		s(cat[i])
		/* code */
	}

	for (int i = 1; i <= v-1; ++i)
	{
		int a, b;
		s(a)
		s(b)
		g[a][b] = 1;
		/* code */
	}
	k = cat[1];
	cat_count = k;
	for (int i = 1; i <= v; ++i)
	{
		if(!visited[i])
		{
			dfs(i, 0);
		}
	}
	p(count)
	
}



/*
6
2
0 1 0 0 0 1
1 2
1 3
1 4
2 5
5 6


7
2
0 1 1 0 0 1 1
1 2
1 3
1 4
2 5
5 6
3 7
*/