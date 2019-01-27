#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int val;
	struct node* prev;
	struct node* next;
} node;

int max=0;
void push(node **head, int x, int y, int z){
	node * newn = (node*)malloc(sizeof(node));
	newn->val = x;
	if(max<x)
		max = x;
	node *temp = *head;
	newn->next = NULL;
	newn->prev = NULL;
	if(temp==NULL || y==0){
		*head = newn;
		
		return;
	}
	
		
	while(temp->next!=NULL &&temp->next->val!=z){
		temp = temp->next;
	}

	temp->next = newn;
	temp = *head;
	// temp = temp->next;
	while(temp->val!=y){
		temp = temp->next;
	}
	newn->prev = temp;
	return;

}

void detectcycleutil(node *temp, int cycle[max+1]){
	int num = temp->val, visited[max+1],  flag=0;
	memset(visited, 0, sizeof(visited));
	
	visited[temp->val] = 1, visited[temp->next->val] = 1;
	temp = temp->next->next;
	while(temp!=NULL){
		visited[temp->val] = 1;
		if(temp->prev->val==num &&cycle[temp->val]==0)
			{
				// printf("in\n");
				flag = 1;
				cycle[temp->val] = 1;
				// break;
			}
			temp = temp->next;
	
	if(flag == 1){
		// printf("in\n");
		for (int i = 0; i <= max; ++i)
		{
			if(visited[i]>0)
			printf("%d ", i);
			/* code */
		}
		printf("\n");
		flag=0;

		}
	}
}
void detectcycle(node *head){
	node *temp= head;
	int cycle[max+1];
	memset(cycle, 0, sizeof(cycle));
	while(temp->next->next!=NULL){
		detectcycleutil(temp, cycle);
		temp = temp->next;
		// printf("\n");
	}
}



void printlist(node *head){
	node *temp = head;
	while(temp!=NULL){
		printf("%d ", temp->val);
		temp = temp->next;
	}
}
void printback(node *head){
	node *temp=head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	while(temp!=NULL){
		printf("%d ",temp->val);
		temp=temp->prev;
	}
}

int main(){
	node* head = NULL;
	int x=0, y, z;
	char temp = ' ';
	int k=2;
	while(temp!='.')
	{
	
		scanf("%d %d %d%c", &x, &y, &z, &temp);
		// print f("%d%d%d",x,y,z);
		push(&head, x, y, z);

	}
	detectcycle(head);
	// printback(head);
}


/*
1 0 2
2 1 3
3 2 4
4 2 5
5 4 0.

*/