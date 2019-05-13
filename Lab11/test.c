#include<stdio.h>  
#include<stdlib.h>
#include<string.h>


typedef struct str{
    char *c;
    int cnt;
   

} string;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    string *list;
    list = (string*)malloc(sizeof(string)*100);
    for(int i = 0; i < n; i++)
    {
        string s;
        char temp[100];
        scanf("%s", temp);
         s.c = (char*)malloc(sizeof(char)*100);
        strcpy(s.c, temp);
        list[i] = s;
    }

    for(int i = 0; i < k; i++)
    {
        char temp[100];
        scanf("%s", temp);
        int f = 0;
        for(int j = 0; j < n; j++)
        {
            if(strcmp(list[j].c, temp)==0){
                list[j].c = ".";
                printf("%d\n", j);
                f = 1;
                break;
            }
        }
        if(f)
            continue;
        else
        {
            printf("NO\n");
            return 0;
        }
        
        
    }
    printf("YES\n");
    
    
}