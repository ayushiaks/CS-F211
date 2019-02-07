#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char *s;
	s = (char*)malloc(sizeof(char)*10);
	scanf("%[^\n]", s);
	int l = strlen(s), ans = 1, count = 0;
	int arr[27];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < l; ++i)
	{
		arr[s[i]-97]++;
		/* code */
	}

	for (int i = 0; i <= 26; ++i)
	{
		
		
		if(arr[i]!=0 && arr[i]%2!=0)
		{
			count++;
		}
		if(count>1)
		{
			ans = 0;
			break;
		}
		/* code */
	}
	
	if(ans==0)
		printf("NO\n");
	else
		printf("YES\n");
}