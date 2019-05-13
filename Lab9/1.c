#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

#define min(a, b) (a<b?a:b);
#define s(x) scanf("%d", &x);
#define p(x) printf("%d\n", x);


typedef struct queue{
    int front, rear, size, capacity;
    int *array;
} queue;

queue* create(int capacity){
    queue *q = (queue*)malloc(sizeof(queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = q->capacity-1;
    q->array = (int*)malloc(q->capacity*sizeof(int));
    return q;
}

int isempty(queue *q){
    return (q->size==0);
}

int isfull(queue *q){
    return (q->size==q->capacity);
}

void push(queue *q, int item){
    if(isfull(q))
        return;
    q->rear = (q->rear+1)%q->capacity;
    q->array[q->rear] = item;
    q->size++;

}

int pop(queue *q){
    if(isempty(q))
        return INT_MIN;
    int item = q->array[q->front];
    q->front = (q->front+1)%q->capacity;
    q->size--;
    return item;

}
int front(queue *q){
    if(isempty(q))
        return INT_MIN;
    return q->array[q->front];
}



int main(){
    int thresh, n;
    double wait = 0;
    s(thresh)
    s(n)
    int at[n], bt[n], wt[n], vis[n];
    memset(vis, 0, n*sizeof(vis[0]));
    for(int i = 0; i < n; i++)
    {
        s(at[i])
        s(bt[i])
    }

    queue *q1 = create(n), *q2 = create(n);
    push(q1, bt[0]);
    push(q2, 0);
    int t = 0; vis[0] = 1;
    while(!isempty(q1)){
        printf("current time ");
        p(t)
        int curr = pop(q1), time = pop(q2);
        printf("curr ");
        p(curr)
        printf("time ");
        p(time)
        for(int i = 1; i < n; i++)
        {
           
            if(t<=at[i] && !vis[i])
            {
                
                push(q1, bt[i]);
                push(q2, at[i]);
                vis[i] = 1;
            }
            if(t>at[i] && !vis[i]){
                wait-=at[i];
                // visu[i] = 1;

            }
        }
        wait += t-time;
        t+=min(thresh, curr);
        if(curr-thresh>0){
            push(q1, curr-thresh);
            push(q2, t);
            // printf("front ");
            // front(q1);
        }
        
      printf("%lf\n", wait);
        
        
    }
    printf("%lf\n", wait/n);

}