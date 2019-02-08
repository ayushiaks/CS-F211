#include<stdio.h>

int n, arr[100000], mid;

int binarysearch(int lo, int hi){
	int ans;
	mid = (lo+hi)/2;
	if(lo==hi)
		return arr[lo];
	if(lo<0)
		return arr[hi];
	if(hi>=n)
		return arr[lo];
	if(mid%2==0)
	{
		if(arr[mid] == arr[mid+1]){
			binarysearch(mid+2, hi);
		}
		else
			binarysearch(lo, mid);
	}
	else{
		if(arr[mid-1] == arr[mid]){
			binarysearch(mid+1, hi);
		}
		else
			binarysearch(lo, mid-1);
	}

}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	printf("%d\n", binarysearch(0, n-1));

	
}