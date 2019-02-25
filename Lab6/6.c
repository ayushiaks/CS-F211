#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define p3(x, y, z) printf("%d %d %d\n", x, y, z);


typedef struct pair{
	int l;
	int r;
} pair;

int count, size;
pair p[50];
char *s;

int compare(const void *a, const void *b){
	pair *t1 = (pair*)a, *t2 = (pair*)b;
	return s[t1->l]-s[t2->l];
}


bool ispalutil(char *s, int start, int end){
	int l = start, r = end;
	while(l<r){
		
		if(s[l]!=s[r])
			return false;
		l++;
		r--;
	}
	if(l>=r)
		return true;
	return false;
}

void ispal(char *s, int l, int r){

	if((r-l)==1)
			return;
	if(ispalutil(s, l, r))
	{

		
		int flag = 1, lo = l;
		while(lo<(r+l)/2){
			// p(l)
			if(s[lo]>s[lo+1])
				{
					flag = 0;
					return;
				}
				lo++;
		}
		if(flag==1){
			// p3(size, l, r)
				p[size].l = l, p[size].r = r;
				size++;
			}
		
	}

	if(size>strlen(s))
		return;
	// printf("before ");
	// p2(l, r)
	ispal(s, l+1, r);
	// printf("after ");
	// p2(l, r)
	ispal(s, l, r-1);
	// exit(0);
 
}

int main(){
	
	s = malloc(sizeof(char)*50);
	scanf("%[^\n]", s);
	int n = strlen(s);
	ispal(s, 0, n-1);
	qsort(p, size, sizeof(pair), compare);
	if(size==0){
		p(-1)
		exit(0);
	}
	for (int i = p[0].l; i <= p[0].r ; ++i)
	{
		printf("%c", s[i]);
		/* code */
	}

}
