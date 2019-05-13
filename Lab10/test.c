#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

#define min(a, b) (a<b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);

typedef struct node{
	int data;
	struct node *next;
}node;

int main(){
	node* arr[5];
	arr[0]->data = 1;
	node *temp;
	temp->data = 5;
	temp->next = NULL;
	arr[0]->next = temp;
	for(int i = 0; i<4; i++){
		if(arr[i]!=NULL){
			while(arr[i]!=NULL){
				p(arr[i]->data);
				arr[i] = arr[i]->next;
			}
		}
	}
}