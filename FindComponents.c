//Kyler Kiminki
//cmps101
//kkiminki
//FindCompnents.c
//Client for Graph DFS ADT

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"
#include"List.h"


int main(int argc, char * argv[]){

   FILE *in, *out;

   if(argc!=3){
      printf("Usage Error: FindPath [inputFile] [outputFile]\n");
      exit(1);
   }

   in = fopen(argv[1], "r");
   out = fopen(argv[2], "w");

   if(in==NULL){
      printf("Unable to read the input file\n");
      exit(1);
   }
   if(out==NULL){
      printf("Unable to write to output file\n");
      exit(1);
   }
   
   int size;
   int source;
   int vertex;

   fscanf(in, "%d", &size);
   Graph G = newGraph(size);
   
   while(1){
      fscanf(in, "%d %d", &source, &vertex);;
      if(source==0 && vertex==0) break;
      addArc(G, source, vertex);
   }

   printGraph(out, G);
   fprintf(out, "\n");

   Graph T = transpose(G);
   
   List L = newList();
   int i;
   for(i=0;i < getOrder(G);i++){
      append(L, i+1);
   }

   DFS(G, L);
   DFS(T, L);
   
   if(L!=NULL && length(L)!=0){
      moveFront(L);
      i=0;
      while(index(L)!=-1){
         if(getParent(T, get(L))==NIL){
            i++;
            fprintf(out, "\nComponent %d: ", i);
         }
         fprintf(out,"%d ",get(L));
         moveNext(L);
      }
      fprintf(out, "\nThere are %d strongly connected components\n", i);
   }
   
   freeList(&L);
   freeGraph(&T);
   freeGraph(&G);
   fclose(in);
   fclose(out);
}

