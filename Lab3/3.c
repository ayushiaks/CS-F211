#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define print(x) printf("%d", x)

typedef struct node{
	int val;
	struct node *next;
} node;

int l, check[100];

void push(int x, node** head){
	node *temp = *head;
	node *newn = (node*)malloc(sizeof(node));
	newn->val = x;
	newn->next = NULL;
	if(*head==NULL)
	{
		*head = newn;
		return;
	}
	while(temp->next!=NULL){
		temp = temp->next;
		
	}
	temp->next= newn;
	

}

void length(node *head){
	node *temp = head;
	while(temp!=NULL){
		temp = temp->next;
		l++;
	}
}

int search(int x, node *head){
	node *temp = head;
	x--;
	while(x-- && temp!=NULL){
		temp = temp->next;
	}
	return temp->val;
}

void printlist(node* head){
	
	while(head!=NULL){
		print(head->val);
		printf(" ");
		head = head->next;
	}
	// printf("\n");
}

void change(node *head, int k){

	node *new = NULL;
	int i = 1, num;
	while((k*i)<=l){
		num = search(k*i, head);
		push(num, &new);
		check[k*i] = 1;
		i++;
	}

	for (int j = l; j >=1; --j)
	{
		
		if(check[j]==0){
			num = search(j, head);
			push(num, &new);
		}

		/* code */
	}

	printlist(new);
}


int main(){
	int k, x;
	node *head = NULL;
	scanf("%d", &k);
	char tmp = ' ';
	
	//scan till new line
	while(tmp!='\n'){
		scanf("%d%c", &x, &tmp);
		push(x, &head);
	}
	length(head);
	change(head, k);
	


}