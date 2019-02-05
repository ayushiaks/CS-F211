#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *s;
	s = (char*)malloc(sizeof(char)*1000);
	int m;
	scanf("%[^\n] %d", s, &m);
	while(m--){
		int f, r, k;
		scanf("%d %d %d", &f, &r, &k);
			
			while(k--){
				char *temp;
				temp = (char*)malloc(sizeof(char)*1000);
				int j = 1;
				// temp[j++] = ' ';
				for (int i = f-1; i < r-1; ++i)
				{
					temp[j] = s[i];
					j++;
					/* code */
				}
				temp[0] = s[r-1];
				j = 0;
				for (int i = f-1; i <= r-1; ++i)
				{
					s[i] = temp[j];
					j++;
					/* code */
				}

		
	
			}
		}
		printf("%s\n", s);
	


}
