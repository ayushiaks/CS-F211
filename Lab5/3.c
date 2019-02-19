#include<stdio.h>
#include<stdlib.h>

#define max(a, b) (a>b?a:b);
#define p(x) printf("%d\n", x);
#define p2(x, y) printf("%d %d\n", x, y);
#define s(x) scanf("%d", &x);

typedef struct node
{
	int data;
	struct node* next;
} node;

int l, arr[10];

void search(node *head, int n, int arr[]){
	node* temp = head;
	l = 0;
	int j=1;
	while(temp!=NULL){
		if(temp->data==n){
			arr[l] = j;
			l++;
		}
		j++;
		temp = temp->next;
	}
}

void delete(node** head, int n){
	search(*head, n, arr);
	
	node* prev = *head;
	node* curr;
	int i = 1;
	while(i<l){
		int j = arr[i];
		node* temp = *head;
		j--;
		while(j-- && temp->next!=NULL){
			prev = temp;
			temp = temp->next;
		}
		if(temp == NULL) return;
		// curr = temp;
		prev->next = temp->next;
		free(temp);
		i++;
	}
}
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

void swap(node *head, int a, int b){
	node* temp = head;
	
	while(temp->next!=NULL && temp->data!=num){
		temp = temp->next;
	}
	if(temp->next == NULL) return;
	int x = temp->data;
	temp->data = temp->next->data;
	temp->next->data = x;
	return;
}

void swapnum(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(node *head){
	node *i = head;
	while(i!=NULL){
		node *j = head;
		while(j->next!=NULL){
			if(j->data>j->next->data)
				swapnum(&(j->data), &(j->next->data));
			j = j->next;
		}
		i = i->next;
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
	node *head = NULL;
	char tmp = ' ';
	int x, k;
	//scan till new line
	while(tmp!='\n'){
		scanf("%d", &x);
		scanf("%c", &tmp);
		push(&head, x);
	}
	sort(head);
	printlist(head);

	// int t;
	// s(t)
	// while(t--){

	// }
}