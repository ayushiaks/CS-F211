#include<stdio.h>
#include<limits.h>

#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);
#define min(a, b) (a<b?a:b);

int pivot, n, arr[100000], x, mini= INT_MAX;

int binarysearch(int lo, int hi){
	int mid = (lo+hi)/2;
	
	// p(pivot);	
	if(hi < 0){
		// printf("hi<0 ");
		// p2(lo, mid, hi);
		hi = n-1;
		return binarysearch(pivot, hi);
	}
	if(lo>hi){
		// printf("lo>hi ");
		// p2(lo, mid, hi);
		lo = 0;
		return binarysearch(lo, pivot-1);
	}
	
	if(arr[mid] == x){
		return mid;
	}
	if(arr[mid]>x){
		// printf("mid>x ");
		// p2(lo, mid, hi);
		return binarysearch(lo, mid-1);
	}
	if(arr[mid]<x){
		// printf("mid<x ");
		// p2(lo, mid, hi);
		return binarysearch(mid+1, hi);
	}

}

int main(){
	s(n);
	for (int i = 0; i < n; ++i)
	{
		s(arr[i]);
		mini = min(mini, arr[i]);
		if(arr[i]==mini)
			pivot = i;
		/* code */
	}
	s(x);
	// pivot = binarysearch(0, n-1);
	p(binarysearch(0, n-1)+1);
	// p(pivot)
}