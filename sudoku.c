#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  //int numero ;
  int sub , contX = 0;
    
    for(int i = 0 ; i < 9 ; i++)
    {
      sub = 0;
      if(i > 2) sub += 3;
      if(i > 5) sub += 3;
      printf("%d\n ", sub);
      for(int j = 0 ; j < 9 ; j++)
      {
        printf("%d , %d\n", contX , sub);
        contX++;
        
        
        if(n->sudo[i][j] != 0)
        {
          //numero = n->sudo[i][j];
          for(int k = 0 ; k < 9 ; k++)
          {
            //recorrer submatriz
            //int auxX = 3*(sub/3) + (k/3);
            //int auxY = 3*(sub%3) + (k%3);
            
            /*if(n->sudo[auxX][auxY] == numero && auxX != i && auxY != j) return 0;
            
            if(n->sudo[i][k] == numero && k != j) return 0;
            if(n->sudo[k][j] == numero && k != i) return 0;*/
          }
        }
        if(contX > 2)
        {
          contX = 0;
          sub++;
        }
      }
    }
  return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i = 0 , j = 0 , cont = 1;
    Node * aux = createNode();
    while(i < 9){
      while(j < 9){
        if(n->sudo[i][j] == 0){
          while(cont < 10){
            n->sudo[i][j] = cont;
            aux = copy(n);
            pushBack(list, aux);
            cont++;
          }
          return list;
        }
        j++;
      }
      i++;
      j = 0;
      
    }
  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/