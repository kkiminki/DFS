//Kyler Kiminki
//kkiminki
//cmps101
//GraphTest
//Tests GRaph ADT

#include<stdlib.h>
#include<stdio.h>
#include"Graph.h"
#include"List.h"

int main(){

   Graph G = newGraph(5);
   addEdge(G, 1, 4);
   addEdge(G, 1, 2);
   addEdge(G, 3, 4);
   addEdge(G, 5, 3);

   printGraph(stdout, G);

   List L = newList();

   int i;
   for(i=0; i<getOrder(G); i++){
      append(L, i+1);
   }

   DFS(G, L);
   
   
   printf("G is of order %d\n", getOrder(G));
   
   printf("The source of BFS was %d\n", get(G, 2));

   printf("The parent of 5 is %d\n", getParent(G, 2));


   printf("Making list null and printing new list (should be nothing)\n");
   printGraph(stdout, G);
   freeList(&L);
   freeGraph(&G);
}
