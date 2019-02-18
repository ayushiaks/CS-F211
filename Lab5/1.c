#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);

int n, arr[10], count=0;

int main(){
	int t;
	s(t)
	while(t--){
		s(n);
		char *name[2] = {"IM", "CA"};
		char *ans[n];
		int arr[10], counter = 1, size = 0, count[2], flag = 1;
		memset(arr, -1, sizeof(arr));
		memset(count, 0, sizeof(count));
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			s(a)
			s(b)
			if((arr[a]!=-1 && arr[a]==(counter+1)%2) || (arr[b]!=-1 && arr[b]==(counter+1)%2))
				{
					ans[size++] = name[(counter+1)%2];
					count[(counter+1)%2]++;
				}
			else
				{
					arr[a] = arr[b] = counter%2;
					ans[size++] = name[counter%2];
					count[(counter)%2]++;
					counter++;
				}
		}
		for (int i = 0; i < 2; ++i)
		{
			if(n!=1 && count[i]==0)
				{
					p(-1)
					flag = 0;
				}
		}
		if(flag==1)
		{	
			for (int i = 0; i < size; ++i)
			{
				printf("%s ", ans[i]);
			}
			printf("\n");
		}
	}
}

/*
1
3
2 3 5 5 3 4
CA IM CA
*/