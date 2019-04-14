#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

#define min(a, b) (a<b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);

int n, arr[100];


void maxheapify(int i){
    int l = 2*i+1, r = 2*i+2, largest = i;
    if(l<n && arr[l]>arr[i])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest!=i)
        {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            maxheapify(largest);
        }
}

void mintomax(){
    for(int i = (n-2)/2; i>=0; i--){
        maxheapify(i);
    }
}

int main(){
    s(n)
    for(int i = 0; i < n; i++)
    {
        s(arr[i])
    }
    mintomax();
    for(int i = 0; i < n; i++)
    {
        p(arr[i])
    }
    
    
}