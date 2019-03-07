#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define ps(c) printf("%s\n", c);
#define p2(x, y) printf("%d %d\n", x, y);

int n;
char *s[100];

int compare(const void *x, const void *y){
	// ps(*(char**)x)
	// ps(*(char**)y)
	char xy[100];
	char yx[100];
	strcpy(xy,*(char**)x);
	strcpy(yx,*(char**)y);
	strcat(xy,*(char**)y);
	strcat(yx,*(char**)x);
	
	// printf("\n");
	return -strcmp(xy, yx);
}

int main(){
	// int n;
	s(n)
	// char *s[n];
	char c, *temp;
	temp = (char*)malloc(sizeof(char)*100);
	size_t malloc_size = 100;
	for (int i = 0; i < n; ++i)
	{
		s[i] = malloc(malloc_size*sizeof(char));
		scanf("%s", s[i]);
		// ps(s[i])
		scanf("%c", &c);
		// s[i] = temp;
		
		/* code */
	}
	
	qsort(s, n, sizeof(char*), compare);
	for (int i = 0; i < n; ++i)
	{
		printf("%s",s[i]);
		/* code */
	}
	// ps(s[0])

}