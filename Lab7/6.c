#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define p3(x, y, z) printf("%d %d %d\n", x, y, z);

int n, k, m;

typedef struct{
	int val;
	bool vis;

} pair;

void permutation(char *p, char *prefix, char *s, int k){
	// p(k)
	if(k==0){
		
		if(strlen(prefix)==m)
			strcat(s, prefix);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		char *temp;
		temp = (char*)malloc(sizeof(char)*100);
		strcpy(temp , prefix);
		int l = strlen(temp);
		temp[l] = p[i];
		permutation(p, temp, s, k-1);
	}
}

int main(){
	char *p, *s;
	p = (char*)malloc(sizeof(char)*100), s = (char*)malloc(sizeof(char)*100);
	s(k)
	s(n)
	char c;
	m = k;
	scanf("%c", &c);
	scanf("%[^\n]", p);
	permutation(p, "", s, k);
	printf("%s\n", s);
	p(strlen(s))
	int ans[strlen(s)], size = 0, seen[100], num = 0;
	memset(ans, 0, sizeof(ans));
	memset(seen, 0, sizeof(ans));
	
	for (int i = 0; i <= strlen(s)-k; ++i)
	{
		if(ans[i]==0){
			char *str;
			str = (char*)malloc(sizeof(char)*100);
			int j = i, count = 0, flag = 0;
			while(count!=k && j<strlen(s))
			{
				if(ans[j]==0){	
					str[count] = s[j];
					count++;
				}
				j++;
				
				/* code */
			}
			
			// printf("\n");
			
			if(seen[atoi(str)]==1){
				p2(atoi(str), j-1)
				printf("seen %s\n", str);
				ans[j-1] = 1;
				flag = 1;
				if((int)strlen(s) == j)
					break;
				
			}
			else{
				p2(i, j-1)
				printf("notseen %s\n", str);
				seen[atoi(str)] = 1;
			}
			if(flag == 1)
				i--;
		}
	}
	for (int i = 0; i < strlen(s); ++i)
	{
		if(ans[i]==0)
			printf("%c", s[i]);
		
	}
	
	
}