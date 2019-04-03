#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define max(a, b)(a>b?a:b)
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);
// #define int unsigned long long int

typedef struct node{
	int priority;
	char data;
	struct node *next;
} node;

node *newnode(char d, int p){
	node *n = (node*)malloc(sizeof(node));
	n->data = d;
	n->priority = p;
	n->next = NULL;
	printf("%c %d\n", n->data, n->priority);
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

void push(node **head, char d, int p){
	node *start = *head;
	node *temp = newnode(d, p);
	if((*head)->priority<=p){
		printf("head\n");
		temp->next = *head;
		*head = temp;
	}
	else{
		p(1)
		while(start->next!=NULL && start->priority>p){
			printf("new\n");
			start = start->next;
		}
		temp->next = start->next;
		start->next = temp;
	}
	printf("%c\n", temp->data);
}

int isempty(node **head){
	return (*head) == NULL;
}

typedef struct key{
	int freq;
	char c;
} key;

void rearrange(char* str){
	int n = strlen(str);
	int count[26] = {0};
	for(int i = 0; i < 26; i++)
	{
		count[str[i]-'a']++;
	}
	node *pq = newnode(str[0], count[str[0]-'a']);
	// p(toppr(&pq))
	for(char c = 'b'; c <= 'z'; c++)
	{
		if(count[c-'a'])
			push(&pq, c, count[c-'a']);
	}
	key prev;
	prev.c = '#';
	prev.freq = -1;
	char *res;
	res= (char*)malloc(sizeof(char)*100);
	// printf("%c", topdata(&pq));
	while(!isempty(&pq)){
		key k;
		k.c = topdata(&pq);
		k.freq = toppr(&pq);
		// printf("%c\n", k.c);
		pop(&pq);
		
		strcat(res, &k.c);
		// p(k.freq)
		if(prev.freq>0){
			if(isempty(&pq))
			pq = newnode(prev.c, prev.freq);
		}
		k.freq--;
		prev = k;
	}

	if(n!=strlen(res))
		printf("NO\n");
	else
		printf("YES\n");
	
}

int main(){
	char *s;
	s = (char*)malloc(sizeof(char)*100);
	scanf("%[^\n]", s);
	rearrange(s);
}

