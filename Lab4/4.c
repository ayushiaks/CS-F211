#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define min(a, b) (a<b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y, z, w) printf("%d %d %d %d\n", x, y, z, w);
#define s(x) scanf("%d", &x);

int n, cost[100000], arr[100000], maxi = INT_MIN;

int cost_at_height(int h){
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		c += abs(h-arr[i])*cost[i];
		/* code */
	}
	return c;
}


int bs(int lo, int hi){
	int ans = INT_MAX;

	int mid;
	while(lo<hi){
		mid = (lo+hi)/2;
		int bm = cost_at_height(mid-1), m = cost_at_height(mid), am = cost_at_height(mid+1);
		
		if(ans == m)
			break;

		ans = min(ans, m);

		if(bm<=m)
			hi = mid-1;
		else if(am<=m)
			lo = mid+1;
	}
	return ans;
}


int main(){
	s(n);
	for (int i = 0; i < n; ++i)
	{
		s(arr[i]);
		if(arr[i]>maxi)
			maxi = arr[i];
		/* code */
	}
	for (int i = 0; i < n; ++i)
	{
		s(cost[i])
		/* code */
	}
	p(bs(0, maxi+1))

}