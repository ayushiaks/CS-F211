#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define s(x) scanf("%d", &x);

int n, m,  arr[20], visited[20];

int compare(const void *a, const void *b){
	return -*(int*)a + *(int*)b;
}

int main(){
	s(n)
	int sum = 0, flag = 0;
	// p(n)
	for (int i = 0; i < n; ++i)
	{
		s(arr[i])
		sum += arr[i];
		/* code */
	}
	qsort(arr, n, sizeof(int), compare);
	int y = sum%3, count = 0;
	// for (int i = 0; i < n; ++i)
	// {
	// 	p2(i, arr[i])
	// 	/* code */
	// }
	// // }
	// p(n)
	// p(arr[4])
	for(int i = n-1; i>=0; i--){
		// p(arr[i])
		// p(i)
		if(arr[i]%3==y)
			{
				// p2(1, i)
				visited[i] = 1;
				flag = 1;
				break;
			}
	}
	if(flag==0){
		y = 3 - y;
		for(int i = n-1; i>=0; i++){
			if(arr[i]%3==y){
				p2(2, i)
				visited[i] = 1;
				count++;
			}
			if(count>=2)
				break;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(visited[i]==0)
			printf("%d", arr[i]);
		/* code */
	}
}