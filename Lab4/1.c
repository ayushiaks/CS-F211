#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y, z, w) printf("%d %d %d %d\n", x, y, z, w);
#define s(x) scanf("%d", &x);

int budget, c, n, arr[100000], k, mini= INT_MAX, flag1, flag2;


int cost(int k){
	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += arr[i] + i*k;
		/* code */
	}
	return ans;
}

void bs(int lo, int hi){
	int mid;
	while(lo<hi){
		mid = (lo+hi)/2;
		c = cost(mid);
		if(c>budget)
			{
				// printf("hi ");
				// p2(lo, hi, c, mid);
				hi = mid;
				if(lo>=hi)
					lo = mid-1;
			}
		else if(c<=budget){
			// printf("lo ");
			// p2(lo, hi, c, mid);
			lo = mid+1;
		}

	}
	p(mid)
	p(c);
	// return lo;
}

int main(){
	int high=0;
	s(n);
	s(budget);
	for (int i = 1; i <= n; ++i)
	{
		s(arr[i])
		high += arr[i]+i*n;
		/* code */
	}
	bs(1, high);
}