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

int max_val(int lo, int hi){
	int maxi = arr[lo];
	for (int i = lo; i <= hi; ++i)
	{
		maxi = max(arr[i], maxi);
		/* code */
	}
	return maxi;
}

int min_val(int lo, int hi){
	int mini = arr[lo];
	for (int i = lo; i <= hi; ++i)
	{
		mini = min(arr[i], mini);
		/* code */
	}
	return mini;
}

int min_removals(int lo, int hi){
	int mn = min_val(lo, hi);
	int mx = max_val(lo, hi);
	// p2(mn, mx)
	if(mx<=2*mn)
		return 0;
	return min(min_removals(lo, hi-1), min_removals(lo+1, hi))+1;
}


int main(){
	s(n)
	for (int i = 0; i < n; ++i)
	{
		s(arr[i])
		/* code */
	}
	p(min_removals(0, n-1))
}
