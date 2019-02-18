#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define min(a, b) (a<b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define s(x) scanf("%d", &x);

typedef struct pair{
	int index;
	int val;
} pair;

int n;

int compare(const void *a, const void *b){
	pair *temp1 = (pair*)a, *temp2 = (pair*)b;
	return temp1->val-temp2->val;
}

int main(){
	s(n)
	pair p[n];
	int visited[n], cycle = 0, mini=0;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; ++i)
	{
		int a;
		s(a)
		p[i].index = i+1;
		p[i].val = a;
		/* code */
	}
	qsort(p, n, sizeof(pair), compare);
	for (int i = 0; i < n-1; ++i)
	{
		if(abs(p[i].val-p[i+1].val)>1)
			{
				p(-1)
				exit(0);
			}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(abs(p[i].val-p[j].val)==1 && !visited[j]){
				p2(p[i].index, p[j].index)
				visited[j] = 1;
			}
			mini = min(mini, abs(p[i].val-p[j].val))
			if(abs(p[i].val-p[j].val)==mini && cycle==0){
				p2(p[i].index, p[j].index)
				cycle = 1;
			}
			/* code */
		}
		/* code */
	}
}