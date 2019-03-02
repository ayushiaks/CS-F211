#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);

int hi, vis[1000];

void dfs(int num){
	if(num>=hi || num<0)
		return;
	if(!vis[num])
		p(num);
	vis[num] = 1;
	int lastdigit = num%10;
	
	if(lastdigit>0)
			dfs((num*10)+(lastdigit-1));
	
	if(lastdigit<9)
	dfs((num*10)+(lastdigit+1));
}

int main(){
	s(hi)
	for (int i = 0; i <= 9; ++i)
	{
		dfs(i);
		/* code */
	}
	
}