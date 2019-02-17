#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);

int n, arr[10], count=0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int compare(const void *a, const void *b){
	int ans = *(int*)a-*(int*)b;
	p2(*(int*)a, *(int*)b, ans)
	if(ans<0)
		count++;
	return ans;
}

int main(){
	s(n)
	for (int i = 0; i < n; ++i)
	{
		/* code */
		s(arr[i])
	}
	qsort(arr, n, sizeof(int), compare);
	p(count)
	for (int i = 0; i < n; ++i)
	{
		// p(arr[i])
		/* code */
	}
}