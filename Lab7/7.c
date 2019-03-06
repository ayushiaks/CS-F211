#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);

typedef struct pair{
	int val;
	int in;
	int fin;
} pair;

int compare(const void *a, const void *b){
	pair *t1 = (pair*)a, *t2 = (pair*)b;
	return t1->val-t2->val;
}


int main(){
	int n, a, count = 0;
	s(n)
	pair p[n];
	for (int i = 0; i < n; ++i)
	{
		s(a);
		p[i].val= a;
		p[i].in = i;
		/* code */
	}
	qsort(p, n, sizeof(pair), compare);
	for (int i = 0; i < n; ++i)
	{
		p[i].fin = i;
		/* code */
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			
			if(p[j].in<p[i].in){
				p2(p[i].val, p[j].val)
				count++;
			}

			/* code */
		}
		/* code */
	}
	p(count)
}