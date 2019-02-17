#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>


#define min(a, b) (a<b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y, z) printf("%d %d %d\n", x, y, z);
#define s(x) scanf("%d", &x);

int compare(const void *a, const void *b){
	return *(int*)a-*(int*)b;

}

int main(){
	int a, b, c, m, l1 = 0, l2 = 0, count = 0, cost = 0;
	s(a)
	s(b)
	s(c)
	s(m)
	int ps[m], xbox[m];
	for (int i = 0; i < m; ++i)
	{
		int x;
		char *s;
		s = malloc(sizeof(char)*50);
		scanf("%d %s", &x, s);;
		if(strcmp(s, "PS4")==0){
			ps[l1++]=x;
		}
		else{
			xbox[l2++]=x;
		}
	}
	
	
	qsort(ps, l1, sizeof(int), compare);
	qsort(xbox, l2, sizeof(int), compare);
	
	
	int i =0;
	while(a-- && i<l1){
		count++;
		cost += ps[i];
		i++;
		
	}
	int j = 0;
	while(b-- && i<l2){
		count++;
		cost += xbox[j];
		j++;
		
	}

	while(c--){
		if(i<l1 && j<l2){
			count++;
			cost += min(ps[i], xbox[j]);
			i++, j++;
			
		}
		else if(i<l1 && j>=l2){
			count++;
			cost += ps[i];
			i++;
			
		}
		else if(i>=l1 && j<l2){
			count++;
			cost += xbox[j];
			j++;
		}
		else
			break;

	}

	p(count)
	p(cost)

}