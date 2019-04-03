#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define min(a, b) (a<b?a:b);
#define max(a, b) (a>b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);

int main(){
    int n;
    s(n)
    int petrol[n], dist[n];
    for(int i = 0; i < n; i++)
    {
        s(petrol[i])
        s(dist[i])
    }
    for(int i = 0; i < n; i++)
    {
        int p = petrol[i], j=i+1;
        if(dist[i]<=p){
            while(j!=i){
                p+=petrol[i];
                if(dist[i]>p)
                    break;
                j = (j+1)%n;
            }
        }
        if(j==i)
            {
                p(i)
                exit(0);
            }
        /* code */
    }
    
}