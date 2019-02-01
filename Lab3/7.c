#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	char *s;
	s = (char *)malloc(sizeof(char)*100);
	scanf("%[^\n]", s);
	int l = strlen(s);
	for (int i = 0; i < l; ++i)
	{
		int x = s[i]+3;
		if(x>122)
			x = x-26;
		s[i] = x;
	}
	printf("%s\n", s);

}