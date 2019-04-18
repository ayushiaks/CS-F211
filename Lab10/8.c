#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

#define min(a, b) (a<b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);

int arr[100], n, k;

void countmaxgap(int l, int r){
    for(int i = 0; i < n; i++)
    {
        if(arr[i]==-1)
            r=i, gap++;
        else
        {   
            
        }
        
    }
    
}


int main(){
    memset(arr, -1, sizeof(arr));

}