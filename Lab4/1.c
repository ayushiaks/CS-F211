#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y, z, w) printf("%d %d %d %d\n", x, y, z, w);
#define s(x) scanf("%d", &x);

int budget, c, n, arr[100000], k, mini= INT_MAX, flag1, flag2;

int compare(const void *a, const void *b){
	return (*(int*)a-*(int*)b);
}

int cost(int k){
	int ans = 0, temp[k+1];
	memset(temp, 0, sizeof(temp));
	for (int i = 1; i <= n; ++i)
	{
		temp[i] = arr[i] + i*k;
		
		/* code */
	}
	qsort(temp, n, sizeof(int), compare);
	for (int i = 1; i <= k; ++i)
	{
		ans += temp[i];
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
				hi = mid;
				if(lo>=hi)
					lo = mid-1;
				hi = mid;					
			}
		else if(c<=budget){
			lo = mid+1;
		}
		

	}
	p(mid)
	p(c);

	
}

int main(){
	
	s(n);
	s(budget);
	for (int i = 1; i <= n; ++i)
	{
		s(arr[i])
		
	}
	bs(0, n+1);
}