#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d", &n);
	int arr[n+2][n+2], check[n+2][n+2], count = 0;
	memset(arr, 0, sizeof(arr));
	memset(check, 0, sizeof(check));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j){
			scanf("%d", &arr[i][j]);
		}
		/* code */
	}
			
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j){
			if(arr[i][j]==1){
				int sum = i+j;
				if((arr[i-1][j]==1 || arr[i+1][j] == 1 || arr[i][j-1] == 1 || arr[i][j+1] == 1)){
					// printf("%d %d\n", i, j);
					check[i][j] = 1;
					count++;
				}	
				for (int w = 1; w < sum; ++w)
				{
					if(check[i][j]!=1 && arr[w][sum-w]==1 && w!=i && (sum-w)!=j)
						{
								// printf("sum %d %d\n", w, sum-w);
								count++;
								check[i][j] = 1;
						}
					/* code */
				}
			}	
		}
	}

	printf("%d\n", count);
}