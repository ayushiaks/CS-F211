#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

#define min(a, b) (a<b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);

int n, k, left[100], right[100];

int compare(const void *a, const void *b){
	return *(int*)b-*(int*)a;
}

int main(){
	s(n)
	s(k)
	for (int i = 0; i < n; ++i)
	{
		s(left[i])
		/* code */
	}
    for(int i = 0; i < n; i++)
    {
        s(right[i])
    }
    qsort(right, n, sizeof(int), compare);
    qsort(left, n, sizeof(int), compare);
    int i = 0, j= 0;
    p(k)
    while(k--){
        int sum1 = right[i]+left[j],
        sum2 = right[i+1] + left[j],
        sum3 = right[i]+left[j+1];
        // p(sum1)
        if(sum1>sum2 && sum1>sum3){
            printf("%d %d\n", right[i], left[j]);
            p(sum1);
            if(sum2>=sum3)
                i++;
            else
                j++;
            
        }
        else if(sum2>sum3){
             printf("%d %d\n", right[i], left[j]);
           p(sum2)
        }
        else if(sum3>sum2){
            printf("%d %d\n", right[i], left[j]);
            p(sum3)
        }

    }
    
}