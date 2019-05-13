#include<stdio.h>

int main()
{
    
        
        int n;
        scanf("%d",&n);

        int a[n];
        int prefix[n];
        int max=-1;
        for(int i=0;i<n;i++){
          scanf("%d",&a[i]);
          if(!a[i]) a[i]=-1;
          
          if(!i)prefix[i]=a[i];
          else prefix[i]=a[i]+prefix[i-1];

          if(prefix[i]>max)max=prefix[i];
        }

        int count=0;
        int hash[1000000]={0};

        for(int i=0;i<n;i++){
          hash[prefix[i]+n]++;
        }


        for(int i=0;i<=max+n;i++){
          if(hash[i]){
            count+= (hash[i]*(hash[i]-1))/2;
          }
        }

        count+= hash[n];

        printf("%d\n",count);

    
    
    return 0;
}