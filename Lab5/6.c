#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);

int n, arr[100];

int merge(int temp[], int lo, int mid, int hi){
	int i = lo, j = mid, k = lo, inv_count = 0;
	while(i<mid && j<=hi){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			inv_count += mid-i;
		}
		// p(inv_count)
	}
	while(i<mid)
		temp[k++] = arr[i++];
	while(j<=hi)
		temp[k++] = arr[j++];
	for (int i = lo; i <= hi; ++i)
	{
		arr[i] = temp[i];
		/* code */
	}
	return inv_count;
}

int mergesortutil(int temp[], int lo, int hi){
	int inv_count=0;
	if(lo<hi){
		int mid = (lo+hi)/2;
		inv_count = mergesortutil(temp, lo, mid);
		inv_count += mergesortutil(temp, mid+1, hi);
		inv_count += merge(temp, lo, mid+1, hi);
	}
	return inv_count;
}

int mergesort(){
	int *temp = (int*)malloc(sizeof(int)*n);
	return mergesortutil(temp, 0, n-1);

}

int main(){
	s(n)
	for (int i = 0; i < n; ++i)
	{
		s(arr[i])
	}
	p(mergesort())
}