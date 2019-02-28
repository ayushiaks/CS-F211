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


struct node* SortedMerge(struct node* a, struct node* b)  
{ 
  struct node* result = NULL; 
  // p(a->data)
  /* Base cases */
  if (a == NULL)  
     return(b); 
  else if (b==NULL)  
     return(a); 
  
  /* Pick either a or b, and recur */
  if (a->data <= b->data)  
  { 
     result = a; 
     result->next = SortedMerge(a->next, b); 
  } 
  else 
  { 
     result = b; 
     result->next = SortedMerge(a, b->next); 
  } 
  return(result); 
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
	node *head1 = NULL, *head2 = NULL, *res = NULL;
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
	
	res = SortedMerge(head1, head2);
	printlist(res);
}
	