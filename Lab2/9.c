#include<stdio.h>
#include<limits.h>

// #inclc  namespace std; 
  
 
int globalmax= INT_MIN, mat[10][10], N;
void printMaxSumSub(int mat[][N], int k) 
{ 
    if (k > N) return; 
  
    int stripSum[N][N], max_sum = INT_MIN; 
  
    for (int j=0; j<N; j++) 
    { 
         int sum = 0; 
        for (int i=0; i<k; i++) 
            sum += mat[i][j]; 
        stripSum[0][j] = sum; 
  
       for (int i=1; i<N-k+1; i++) 
        { 
            sum += (mat[i+k-1][j] - mat[i-1][j]); 
            stripSum[i][j] = sum; 
        } 
    } 
  
     // int  *pos = NULL; 
  
   for (int i=0; i<N-k+1; i++) 
    { 
       int sum = 0; 
        for (int j = 0; j<k; j++) 
            sum += stripSum[i][j]; 
  
        if (sum > max_sum) 
        { 
            max_sum = sum; 
            // pos = &(mat[i][0]); 
        } 
  
       
        for (int j=1; j<N-k+1; j++) 
        { 
            sum += (stripSum[i][j+k-1] - stripSum[i][j-1]); 
  
            if (sum > max_sum) 
            { 
                max_sum = sum; 
                // pos = &(mat[i][j]); 
            } 
        } 
    } 
  	if(max_sum > globalmax)
  		globalmax = max_sum;
    // for (int i=0; i<k; i++) 
    // { 
    //     for (int j=0; j<k; j++) 
    //         // cout << *(pos + i*N + j) << " "; 
    //     cout << endl; 
    // } 
} 

void allk(int n){
	for (int i = 0; i < n; ++i)
	{
		printMaxSumSub(mat, 3);
		/* code */
	}
}



int main(){
	// int n;
	scanf("%d", &N);
	// int arr[n][n];
	for (int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N ;j++)
			scanf("%d", &mat[i][j]);
	}
	allk(N);
	printf("%d\n", globalmax);

}