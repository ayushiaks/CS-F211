#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int vertex;
    struct node* next;
} node;

typedef struct graph{
    int numvertices;
    node** adjlists;
} graph;

node* createnode(int v){
    node* newn = (node*)malloc(sizeof(node));
    newn->vertex = v;
    newn->next = NULL;
    return newn;
}

graph* creategraph(int vertices){
    graph* g  = (graph*)malloc(vertices*sizeof(graph));
    g->numvertices = vertices;
    g->adjlists = (node**)malloc(vertices*sizeof(node*));
    for (int i = 0; i < vertices; ++i)
    {
        g->adjlists[i] = NULL;
        /* code */
    }
    return g;
}

void addEdge(graph* g, int src, int dest){
    node* newn = createnode(dest);
    newn->next = g->adjlists[src];
    g->adjlists[src] = newn;

    newn = createnode(src);
    newn->next = g->adjlists[dest];
    g->adjlists[dest] = newn;
}

void printgraph(graph* g){
    
    for (int i = 0; i < g->numvertices; ++i)
    {
        node* temp = g->adjlists[i];
        printf("Adj list of vertex %d: ", i);
        while(temp){
            printf("%d->", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
        /* code */
    }
}

int main(){
    graph* g = creategraph(6);
     addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 4);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);
    addEdge(g, 4, 6);
    addEdge(g, 5, 1);
    addEdge(g, 5, 6);
 
    printgraph(g);
 
    return 0;
}