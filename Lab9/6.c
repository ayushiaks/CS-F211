#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

// #define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define min(a, b) (a<b?a:b)


int n, arr[100][100];

int fn(int i, int j, int prev){
    
    if(i>=n || j>=n)
        return INT_MAX;
    // p(arr[i][j])
    if(i==n-1 && j==n-1)
        return (arr[i][j]-prev)>0?(arr[i][j]-prev):0;
    
    // else if(i!=0 && j!=0)
    //     return arr[i][j];
    // p(arr[i][j])
    // printf("%d %d\n", i, j);
    return arr[i][j]-prev + min(fn(i+1, j, arr[i][j]), fn(i, j+1, arr[i][j]));
}

int main(){
    // int n;
    scanf("%d", &n);
    // int arr[n][n];
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            arr[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            /* code */
        }
        
        /* code */
    }
    
    p(fn(0, 0, 0))
}