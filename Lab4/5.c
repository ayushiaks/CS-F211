#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);

int n, m, arr[100000];

int itemsAtT(int t){
	int items = 0;
	for (int i = 0; i < n; ++i)
	{
		items += t/arr[i];
		/* code */
	}
	return items;
}

int bs(int lo, int hi){
	int mid;
	while(lo<hi){
		mid = (lo+hi)/2;

		int items = itemsAtT(mid);
		// p(items)
		if(items < m)
			lo = mid+1;
		else
			hi = mid;

	}
	return mid;
}

int main(){
	int maxi = INT_MIN;
	s(n)
	s(m)
	for (int i = 0; i < n; ++i)
	{
		s(arr[i])
		maxi = max(maxi, arr[i]);
		/* code */
	}
	p(bs(1, m*maxi));
}