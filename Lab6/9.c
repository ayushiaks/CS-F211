#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define max(a, b) (a>b?a:b)


int main(){
	int n;
	s(n)
	int ans = n;
	for (int i = 1; i < n-2; ++i)
	{
		// p2(i, (n-i-2)*i+i)
		ans = max(ans, (n-i-2)*i+i);
		/* code */
	}
	p(ans)
}