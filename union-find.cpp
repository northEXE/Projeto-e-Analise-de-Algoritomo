#include "union_find.hpp" 

// Aloca memória, inicializa e retorna o nó.

Node* make_set(char id){
  Node *x = new Node();
  x->pai = x;
  x->rank = 0;
  x->id = id;
  return x; 
}

Node* find_set(Node *x){
  if(x->pai != x)
    X->pai = find_set(x->pai);
  return x->pai;
}

void uf_union(Node *x, Node *y){
  x1 = find_set(x);
  y1 = find_set(y);
  if(x1->rank > y1->rank)
    y1->pai = x1;
  else{
    x1->pai = y1;
    if(x1->rank == y1->rank)
      y1->rank += 1; 
  } 

}