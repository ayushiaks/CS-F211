#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);

typedef struct node
{
	int data;
	struct node* next;
} node;

int l, arr[10];


void push(node** head, int new){
	node* newn = (node*)malloc(sizeof(node));
	node* last = *head;
	newn->data = new;
	newn->next = NULL;
	
		if(*head == NULL){
			*head = newn;
			return;
		}
		while(last->next!=NULL){
			last = last->next;
		}
		last->next = newn;
		return;
	}


void merge(node **head1, node **head2){
	int new = 0;
	node *a = *head1, *b = *head2;
	node *preva = a, *prevb = b;
	while(a!=NULL && b!=NULL){
		if(a->data>b->data){
			// preva = a;
			preva->next = b;
			b->next = a;
			prevb = b;
			b = b->next;
			a = preva;
			// a = a->next;
		}
		else
			{	
				preva = a;
				a= a->next;
			}
	}
	while(a!=NULL){

	}

}
void printlist(node* head){
	
	while(head!=NULL){
		printf("%d ",head->data);
		if(head->next!=NULL) printf("->");
		head = head->next;
	}
	// printf("\n");
}

int main(){
	int n, m, x;
	node *head1 = NULL, *head2 = NULL;
	s(n)
	for (int i = 0; i < n; ++i)
	{
		s(x)
		push(&head1, x);
		/* code */
	}
	s(m)
	for (int i = 0; i < m; ++i)
	{
		s(x)
		push(&head2, x);
		/* code */
	}
	merge(&head1, &head2);
	printlist(head1);
}