#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define max(a, b) (a>b?a:b);
#define min(a, b) (a<b?a:b)
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define s(x) scanf("%d", &x);

int n, arr[20], count=0;

int compare(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	s(n)
	for (int i = 0; i < n; ++i)
	{
		s(arr[i])
		/* code */
	}
	qsort(arr, n, sizeof(int), compare);
	int res = n-1, j;
	for (int i = 0; i < n; ++i)
	{
		for (j = n-1; j >=0; --j)
		{
			if(arr[i]!=arr[i+1] && arr[j]!=arr[j-1]){

				if(arr[j]<=2*arr[i])
					break;
			}
			/* code */
		}
		
		res = min(res, n-(j-i)-1);
		/* code */
	}
	p(res)
}
