#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);


int compare(const void *a, const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
	int n, m, sum = 0, c=0;
	s(n) s(m)
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		s(arr[i])
		/* code */
	}
	if(n==1)
	{
		p(0)
		exit(0);
	}
	qsort(arr, n, sizeof(int), compare);
	for (int i = 0; i <n-1 ; ++i)
	{
		sum+=arr[i]-1;
		if(arr[i]>c)
			c++;
	}
	if(arr[n-1]==c)
		sum+=arr[n-1]-1;
	else
		sum+=c;
	p(sum)
}