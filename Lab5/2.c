#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);

int n, m,  a2[20], visited[20];

typedef struct pair{
	int index;
	int val;
} pair;


int compare(const void *a, const void *b){
	pair *temp1 = (pair*)a, *temp2 = (pair*)b;
	int i1=INT_MAX, i2=INT_MAX;
	for (int i = 0; i < m; ++i)
	{
		if(a2[i]==temp1->val)
			i1 = i;
		if(a2[i]==temp2->val)
			i2 = i;
		/* code */
	}
	
	if(i1==INT_MAX && i2==INT_MAX)
		return temp1->val-temp2->val;
	else if(i1!=INT_MAX || i2!=INT_MAX)
		return  i1-i2;
	
	
}

int main(){
	s(n)
	s(m)
	pair p[n];
	for (int i = 0; i < n; ++i)
	{
		int a;
		s(a)
		p[i].index = i+1;
		p[i].val = a;
		/* code */
	}
	for (int i = 0; i < m; ++i)
	{
		s(a2[i])
		/* code */
	}
	qsort(p, n, sizeof(pair), compare);
	for (int i = 0; i < n; ++i)
	{
		p(p[i].val)
		/* code */
	}
}