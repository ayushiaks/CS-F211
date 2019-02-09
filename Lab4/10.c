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
			return binarysearch(mid+2, hi);
		}
		else
			return binarysearch(lo, mid);
	}
	else{
		if(arr[mid-1] == arr[mid]){
			return binarysearch(mid+1, hi);
		}
		else
			return binarysearch(lo, mid-1);
	}

}
//Alternative
void xor(){
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		res = res ^ arr[i];
		/* code */
	}
	printf("%d\n", res);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	printf("%d\n", binarysearch(0, n-1));

	//xor();
}