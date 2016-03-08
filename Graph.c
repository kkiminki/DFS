//Kyler Kiminki
//kkiminki
//cmps101
//Graph.c
//Graph ADT

#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include"Graph.h"

//Graph struct

typedef struct GraphObj{
   List *adjList;
   int *color;
   int *parent;
   int *dist;
   int *finish;
   int order;
   int size;
   int source;
   int time;
} GraphObj;

//Constructors ~ Destructors

Graph newGraph(int n){
   Graph G = malloc(sizeof(GraphObj));
   G->adjList = malloc((n+1) * sizeof(List));
   G->color = malloc((n+1) * sizeof(int));
   G->parent = malloc((n+1) * sizeof(int));
   G->dist = malloc((n+1) * sizeof(int));
   G->finish = malloc((n+1) * sizeof(int));
   int i;
   for(i= 1; i < n+1; i++){
      G->adjList[i] = newList();
      G->color[i] = WHITE;
      G->parent[i] = NIL;
      G->dist[i] = INF;
      G->finish[i] = INF;
   }
   G->size = NIL;
   G->source = NIL;
   G->order = n;
   return G;
}

void freeGraph(Graph *pG){
   int i;
   Graph G = *pG;
   for(i = 0; i < G->order + 1; i++){
      freeList(&G->adjList[i]);
   }
   free(G->color);
   free(G->parent);
   free(G->dist);
   free(G->adjList);
   free(*pG);
   pG = NULL;
}

//Access Functions

int getOrder(Graph G){
   return G->order;
}

int getSize(Graph G){
   return G->size;
}

int getParent(Graph G, int u){
   return G->parent[u];
}

int getDiscover(Graph G, int u){
   return G->dist[u];
}

int getFinish(Graph G, int u){
   return G->finish[u];
}

//Manipulation procedures

void addEdge(Graph G, int u, int v){
   addArc(G, u, v);
   addArc(G, v, u);
   G->size--;
}

void addArc(Graph G, int u, int v){
   if(length(G->adjList[u])==0){
      append(G->adjList[u], v);
   }else{
      moveFront(G->adjList[u]);
      while(index(G->adjList[u])!=-1){
         if(get(G->adjList[u]) < v){
            moveNext(G->adjList[u]);
            continue;
         }else{
            insertBefore(G->adjList[u], v); 
            return;
         }
      }
      append(G->adjList[u], v);
   }
}

void DFS(Graph G, List S){
   G->time = 0;
   List L = copyList(S);
   int i;
   clear(S);
   for(i=1; i<G->order;i++){
      G->color[i] = WHITE;
      G->parent[i] = NIL;
   }
   moveFront(L);
   while(index(L)!=-1){
      if(G->color[get(L)]==WHITE){
         Visit(G, get(L), S);
      }
      moveNext(L);
   }
}

void Visit(Graph G, int u, List L){
   G->color[u] = GRAY;
   G->dist[u] = ++G->time;
   if(length(G->adjList[u])!=0){
      moveFront(G->adjList[u]);
      while(index(G->adjList[u])!=-1){
         int y;
         y = get(G->adjList[u]);
         if(G->color[y] == WHITE){
            G->parent[y] = u;
            Visit(G, y, L);
         }
         moveNext(G->adjList[u]);
      }
   }
   push(L, u);
   G->color[u] = BLACK;
   G->finish[u] = ++G->time;
}

void push(List L, int u){
   prepend(L, u);
}

int pop(List L){
   int i;
   i = front(L);
   deleteFront(L);
   return i;
}

void printGraph(FILE* out, Graph G){
   int i;
   for(i = 1; i < G->order + 1; i++){
      fprintf(out, "%d: ", i);
      if(length(G->adjList[i])!=0)
         printList(out, G->adjList[i]);
      fprintf(out, "\n");
   }
}

void Enqueue(List L, int item){
   append(L, item);
}

int Dequeue(List L){
   int i = front(L);
   deleteFront(L);
   return i;
}

Graph transpose(Graph G){
   Graph m = newGraph(getOrder(G));
   int i;
   for(i=1; i < G->order+1;i++){
      if(length(G->adjList[i])==0){
         continue;
      }
      moveFront(G->adjList[i]);
      while(index(G->adjList[i])!=-1){
         addArc(m, get(G->adjList[i]), i);
         moveNext(G->adjList[i]);
      }
   }
   return m;
}

Graph copyGraph(Graph G){
   Graph m = newGraph(getOrder(G));
   int i;
   for(i=1;i<G->order+1;i++){
      if(length(G->adjList[i])==0){
         continue;
      }
      moveFront(G->adjList[i]);
      while(index(G->adjList[i])!=-1){
         addArc(m, i, get(G->adjList[i]));
         moveNext(G->adjList[i]);
      }
   }
   return m;
}
