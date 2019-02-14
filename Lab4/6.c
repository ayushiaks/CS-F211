#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);
#define min(a, b) (a<b?a:b);

int pivot, n, arr[100000], mini= INT_MAX, flag1, flag2;

int compare(const void *a, const void *b){
	return (*(int*)a-*(int*)b);
}

int binarysearch(int lo, int hi, int x){
	int mid = (lo+hi)/2;
	
	if(lo<=hi){
		if(arr[mid] == x){
			return mid;
		}
		if(arr[mid]>x){
			return binarysearch(lo, mid-1, x);
		}
		if(arr[mid]<x){
			return binarysearch(mid+1, hi, x);
		}
	}
	return -1;
}

int main(){
	s(n);
	for (int i = 0; i < n; ++i)
	{
		s(arr[i]);
		
	}

	int ans, d;
	s(d);
	qsort(arr, n, sizeof(int), compare);
	for (int i = 0; i < n; ++i)
	{
		ans = binarysearch(i, n-1, arr[i]+d);
		if(ans!=-1)
			{
				p(arr[i]+arr[ans]);
				exit(0);
			}
		/* code */
	}
	p(-1);
}