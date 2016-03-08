//Kyler Kiminki
//kkiminki
//cmps101
//FindPath.c
//Client for the BFS Graph ADT

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
      addEdge(G, source, vertex);
   }

   printGraph(out, G);
   fprintf(out, "\n");

   while(1){
      fscanf(in, "%d %d", &source, &vertex);
      if(source==0 && vertex==0) break;
      BFS(G, source);
      if(getDist(G, vertex)==INF){
         fprintf(out, "The distance from %d to %d is infinity\nNo %d - %d path exists\n\n", source, vertex, source, vertex);
      continue;
      }
      List L = newList();
      getPath(L, G, vertex);
      fprintf(out, "The distance from %d to %d is %d\nThe shortest %d - %d path is: ", source, vertex, getDist(G, vertex), source, vertex);
      printList(out, L);
      fprintf(out, "\n\n");
      freeList(&L);
   }
   freeGraph(&G);
   fclose(in);
   fclose(out);
}

   /*char inputFile[MAX_LEN];
   while(count < MAX_LEN){
      char *line = fgets(buffer, MAX_LEN, in);
      if(line==NULL) break;
      line = strchr(buffer, '\n');
      if(line==NULL){
         line='\0';
      }else{
         line = buffer;
      }
      char *linestr = malloc(sizeof(char *[MAX_LEN]));*/
