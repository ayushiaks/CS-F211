#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define min(a, b) (a<b?a:b);
#define max(a, b) (a>b?a:b);
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



int main()
{
    int n,que;
    s(que);
    
    while (que--)
    {
        int dis[n];
        s(n);
        if(n == 0)
        {
            p(0);
            continue;
        }
        queue *q =create(n);
        push(q, n);
        dis[n] = 1;
        while (!isempty(q))
        {
            int now = front(q);
            pop(q);
            if(dis[now-1] == 0)
            {
                dis[now-1] = dis[now]+1;
                if(now -1 == 0)
                    break;
                push(q, now-1);
            }
            for(int i = 2; i*i <= now; i++)
            {
                if(now%i == 0)
                {
                    int fac = max(i, now/i);
                    if(dis[fac] == 0)
                    {
                        dis[fac] = dis[now]+1;
                        push(q, fac);
                    }
                }
            }
        }
       p(dis[0]-1);
        memset(dis,0,sizeof(dis));
    }
    return 0;
}
