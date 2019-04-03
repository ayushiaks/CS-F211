#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

#define min(a, b) (a<b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);


int A[100002],B[100002];

int main(){
    int t;
    s(t);
    while (t--) {
        int n, m ,ms;
        scanf("%d%d%d", &n, &m, &ms);
 
        for(int A_i = 0; A_i < n; A_i++){
            scanf("%d",&A[A_i]);
        }
        for(int B_i = 0; B_i < m; B_i++){
           scanf("%d",&B[B_i]);
        }

        int sum = 0;
        int x = 0, y = 0;

        while (x < n && sum + A[x] <= ms) {
            sum += A[x++];
        }

        int ans = x;

        while (y < m && x >= 0) {
            sum += B[y++];
            while (sum > ms && x >= 0) {
                sum -= A[--x];
            }

            if (sum <= ms && ans < x + y) {
                ans = x + y;
            }
            printf("%d %d\n", sum, ans);
        }

        printf("%d\n",ans);
    }
    return 0;
}
