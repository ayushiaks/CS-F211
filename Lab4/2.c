#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);
#define min(a, b) (a<b?a:b);

int pivot, n, arr[100000], k, mini= INT_MAX, flag1, flag2;

int findv(int v){
	int ans = v, i=1, t = 1;
	while((v/t)>0){
		t = pow(k, i);
		ans += v/t;
		
		// p2(ans, v, t)
		i++;
	}
	return ans;
}

int bs(int lo, int hi){
	int mid;
	while(lo<hi){
		mid = (lo+hi)/2;
		int temp = findv(mid);
		if(temp<n){
			lo = mid+1;
		}
		else if(mid==n)
			return mid;
		else{
			hi = mid;
		}
	}
	
}

int main(){
	s(n)
	s(k)
	p(bs(1, n));
	// p(findv(4));

}