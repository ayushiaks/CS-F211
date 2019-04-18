#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

#define min(a, b) (a<b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);

int countSubarrWithEqualZeroAndOne(int arr[], int n){ 
  int mp[100];
  memset(mp, 0, sizeof(mp));
  int sum=0; 
  int count=0; 
  mp[-1] = 0, mp[-2] = 0;
  p(mp[-1])
  for (int i = 0; i < n; i++) { 
      p(i)
            //Replacing 0's in array with -1 
            if (arr[i] == 0) 
                sum+=-1; 
            else
            sum += arr[i]; 
            printf("%d %d %d\n", sum, i, arr[i]);
            //If sum = 0, it implies number of 0's and 1's are 
            //equal from arr[0]..arr[i] 
            if (sum == 0) 
                count++; 
           
            if (mp[sum]){
                //  printf("%d %d\n", sum, mp[sum]);
                count += mp[sum]; 
            }
            if(mp[sum]==0) 
                mp[sum]=1; 
            else
                mp[sum]++; 
            // printf("%d %d\n", i, count);
  
        } 
  return count; 
} 
  
int main() 
{ 
  int arr[] = {1, 0, 0, 1, 0, 1, 1}; 
  
  int n = sizeof(arr)/sizeof(arr[0]); 
  
  p(countSubarrWithEqualZeroAndOne(arr, n)); 
} 