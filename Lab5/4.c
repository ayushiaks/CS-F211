#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define min(a, b) (a< b?a:b)
#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);

int n, arr[10], count1=0, count2 = 0;

typedef struct pair{
	int index;
	int val;
} pair;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int comparerev(const void *a, const void *b){
	pair *t1 = (pair*)a, *t2 = (pair*)b;
	return -t1->val+t2->val;
}

int compare(const void *a, const void *b){
	pair *t1 = (pair*)a, *t2 = (pair*)b;
	return t1->val-t2->val;
}

int main(){
	s(n)
	int a;
	pair p[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		s(a)
		p[i].index = i;
		p[i].val = a;
	}
	qsort(p, n, sizeof(pair), compare);

	// p(count)
	for (int i = 0; i < n; ++i)
	{
		if(p[i].index !=i)
		{
			swap(&p[i].val, &p[p[i].index].val);
			swap(&p[i].index, &p[p[i].index].index);
			count1++;
		}
	}

	qsort(p, n, sizeof(pair), comparerev);
	// p(count)
	for (int i = 0; i < n; ++i)
	{
		if(p[i].index == i)
			continue;
		else
		{
			swap(&p[i].val, &p[p[i].index].val);
			swap(&p[i].index, &p[p[i].index].index);
			count2++;
		}
	}
	p(min(count1, count2))
}