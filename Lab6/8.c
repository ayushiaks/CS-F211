#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);

int n, flag;
char g[10][10];

void ispresent(int i, int j, char *s, int c){
	if(c>strlen(s))
		{
			printf("yes\n");
			flag = 1;
			return;
		}
	// p2(i, j)
	if(g[i+1][j]==s[c])
		ispresent(i+1, j, s, c+1);
	if(g[i-1][j]==s[c])
		ispresent(i-1, j, s, c+1);
	if(g[i][j+1]==s[c])
		ispresent(i, j+1, s, c+1);
	if(g[i][j-1]==s[c])
		ispresent(i, j-1, s, c+1);
	// else
	// {
		
	// 	return 0;
	// }

}

int main(){
	int n, m;
	s(n)
	s(m)
	char t;
	scanf("%c", &t);
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j <m; j++){
			scanf("%c", &g[i][j]);
			// printf("%c ", g[i][j]);
		}
		char t;
		scanf("%c", &t);
		/* code */
	}
	
	char *s;
	s = malloc(sizeof(char)*50);
	scanf("%[^\n]", s);
	// printf("%s\n", s);
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j <m; j++){
			if(g[i][j]==s[0]){
				// p2(i, j)
				ispresent(i, j, s, 1);
				
			}
		}
	}
	if(flag==0)
		printf("No\n");
}
