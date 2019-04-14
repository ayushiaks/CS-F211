#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

#define min(a, b) (a<b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);

int n, tree[100];

int main(){
    int flag= 0;
    s(n)
    for(int i = 0; i < n; i++)
    {
        s(tree[i])
    }
    for(int i = 0; i < (n/2)-1; i++)
    {
        if(tree[2*i+1]>tree[i] && tree[2*i+2]>tree[i])
            continue;
        else
        {
            p(tree[i])
            flag = 1;
            break;
        }
        
    }
    if(flag)
        printf("FALSE");
    else
    {
        printf("TRUE");
    }
    
    
}