
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
}

bool isPalindrome(char* s)
{
    int i=0, j = strlen(s)-1;
    int f=0;
    while(1)
    {
        if(i==j)
            return true;
        else if((j-i)==1&&s[i]==s[j])
            return true;
        else if((j-i)==1&&s[i]!=s[j])
            break;
        
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
            break;


    }

    return false;
}

void generatePermutation(char* s, int l, int r)
{
    if(l==r)
    {
        if(isPalindrome(s))
        {
            printf("%s\n", s);
            printf("Yes");
            exit(0);
        }
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap((s+l), (s+i));
            generatePermutation(s,l+1,r);
            swap((s+l), (s+i));
        }
    }
}

int main()
{
    char str[11];
    scanf("%s", str);
    generatePermutation(str,0,strlen(str)-1);
    printf("No");
}

/*
    Alternative
    Only one alphabet occurring odd number of times is accepted.

    char *s;
    s = (char*)malloc(sizeof(char)*10);
    scanf("%[^\n]", s);
    int l = strlen(s), ans = 1, count = 0;
    int arr[27];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < l; ++i)
    {
        arr[s[i]-97]++;
       
    }

    for (int i = 0; i <= 26; ++i)
    {
        
        
        if(arr[i]!=0 && arr[i]%2!=0)
        {
            count++;
        }
        if(count>1)
        {
            ans = 0;
            break;
        }
       
    }
    
    if(ans==0)
        printf("NO\n");
    else
        printf("YES\n");
}

*/