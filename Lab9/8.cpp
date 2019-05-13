#include<bits/stdc++.h>
using namespace std;
#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);

typedef struct node{
	int priority;
	char data;
	struct node *next;
    struct node *prev;
} node;

node *newnode(int d, int p){
	node *n = (node*)malloc(sizeof(node));
	n->data = d;
	n->priority = p;
	n->next = NULL;
	return n;
}

char topdata(node **head){
	return (*head)->data;
}

int toppr(node **head){
	return (*head)->priority;
}

void pop(node **head){
	node *temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

void push(node **head, int d, int p){
	node *start = *head, *prev = *head;
	node *temp = newnode(d, p);
	if((*head)->priority>p){
		temp->next = *head;
		*head = temp;
	}
	else{

		while(start->next!=NULL && start->priority<p)
			prev = start, start = start->next;
        if(start->priority==p){
            while(start->data>d && start->next!=NULL){
                p(start->data)
                prev = start;
                start = start->next;
            }
            // printf("%d %d\n", start->data, d);
            
            prev->next = temp;
            temp->next = start;
        }
        else{
		    temp->next = start->next;
	    	start->next = temp;
        }
	}
}

int isempty(node **head){
	return (*head) == NULL;
}

int main(){
    int k, cap, n, res=0;
    s(k) s(cap) s(n)
    int d[n], p[n]; 
    for(int i = 0; i < n; i++)
    {
        s(p[i])
    }
    for(int i = 0; i < n; i++)
    {
        s(d[i])
    }
    node *pq = newnode(d[0], p[0]);
    for(int i = 1; i < n; i++)
    {
        push(&pq, d[i], p[i]);
    }
    
    int count = 0;
    while(!isempty(&pq)){
       int d = topdata(&pq), p = toppr(&pq);
       printf("%d %d %d\n", d, p, cap);
       if(p<=cap && count<k){
        //    p(d)
           res+=d;
        //    p~(res)
           cap = cap+d-p;
           count++;
           pop(&pq);
       }
       else
        break;
        // printf("%d %d\n", d, p);
        // pop(&pq);
    }
    p(count)
    p(res)
    
    
}
/*
2
0
4
0 1 1 4
4 2 3 4
4 0 0
3 1 4
2 1 6
2
7
*/