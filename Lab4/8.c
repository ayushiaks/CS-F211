#include<stdio.h>
#include<stdlib.h>

#define p(x) printf("%d\n", x);
int n, arr[100000],  x;

int binarysearch(int lo, int hi){
	int mid = (lo+hi)/2;
	// p(mid)
	if(lo>hi)
		{
			printf("Sasuke, %d\n", lo);
			exit(0);
		}
	
	if(arr[mid]==x){
		return mid;
		
	}
	
	if(arr[mid]>x){
		return binarysearch(lo, mid-1);
	}
	if(arr[mid]<x){
		return binarysearch(mid+1, hi);
	}
	
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		/* code */
	}
	
	scanf("%d", &x);
	printf("Naruto, %d\n", binarysearch(0, n-1));
	// p(ans)
	

	
}