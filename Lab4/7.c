#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);
#define min(a, b) (a<b?a:b);

int pivot, n, arr[100000], x, mini= INT_MAX, flag1, flag2;

int binarysearch(int lo, int hi){
	int mid = (lo+hi)/2;
	
	if(lo<=hi){
		if(arr[mid] == x){
			return mid;
		}
		if(arr[mid]>x){
			return binarysearch(lo, mid-1);
		}
		if(arr[mid]<x){
			return binarysearch(mid+1, hi);
		}
	}
	return -1;
}

int findpivot(int lo, int hi){
	int mid;
	if(hi < lo)
		return -1;
	if(hi == lo)
		return lo;
	mid = (lo+hi)/2;
	if(mid<hi && arr[mid]>arr[mid+1]) 
		return mid;
	else if(lo<mid && arr[mid]<arr[mid-1])
		return mid-1;
	else																																																																																																																																
		return findpivot(lo, mid-1);
	return findpivot(mid+1, hi);
}

int main(){
	s(n);
	for (int i = 0; i < n; ++i)
	{
		s(arr[i]);
		if(i!=0 && arr[i]<arr[i-1])
			pivot = i;
		/* code */
	}
	s(x);

	// pivot = findpivot(0, n-1);
	int ans;
	pivot = findpivot(0, n-1);
	if(pivot == -1)
		ans = binarysearch(0, n-1);
	else{
		ans = binarysearch(0, pivot);
		if(ans==-1)
			ans = binarysearch(pivot+1, n-1);
	}
	p(ans);
	
}
