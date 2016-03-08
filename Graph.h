//Kyler Kiminki
//kkiminki
//cmps101
//Graph.h
//Header file for the graph ADT

#include"List.h"

#define INF -1
#define NIL 0
#define WHITE -3
#define GRAY -4
#define BLACK -5

//Exported type
typedef struct GraphObj* Graph;

//Constructors~Destructors
Graph newGraph(int n);
void freeGraph(Graph* pG);

//Access functions
int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDiscover(Graph G, int u);
int getFinish(Graph G, int u);
void getPath(List L, Graph G, int u);

//Manipulation Procedures
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void DFS(Graph G, List S);

//Other operations
void printGraph(FILE* out, Graph G);
void Enqueue(List L, int item);
int Dequeue(List L);
void push(List L, int u);
int pop(List L);
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void Visit(Graph G, int u,  List L);
