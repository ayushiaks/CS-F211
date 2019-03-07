#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int n;
int arr[100];
bool visited[100];
int group[100];
int g=0;
int res=0;

int main()
{
	printf("Enter n\n");
	scanf("%d",&n);
	int root=-1;

	for(int i=1;i<=n;i++)
	{
		scanf(" %d",&arr[i]);
		if(i==arr[i])
			root=i;
	}

	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			g++;
			int v=i;
			group[v]=g;
			visited[v]=true;

			while(group[arr[v]]==0)
			{
				v=arr[v];
				group[v]=g;
				visited[v]=true;
			}
			if(group[arr[v]]==g)
			{
				if(root==-1)
					root=v;
				if(arr[v]!=root)
				{
					res++;
					arr[v]=root;
				}
			}
		}
	}

	printf("%d \n",res);
	for(int i=1;i<=n;i++)
		printf("%d ",arr[i]);

	return 0;
}