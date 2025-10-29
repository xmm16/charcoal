#include "tree.h"
#include <stdlib.h>

p_node create_tree(p_node_t type, p_node_r rank, size_t start, size_t end){
  p_node result;
  result.type = type;
  result.rank = rank;
  result.start = start;
  result.end = end;
  result.left = malloc(sizeof(p_node*));
  result.right = malloc(sizeof(p_node*));
  result.back = NULL; 
  return result;
}

void insert_tree(p_node* tree, p_node* back, p_node_t type, p_node_r rank, size_t start, size_t end){
  tree->type = type;
  tree->rank = rank;
  tree->start = start;
  tree->end = end;
  tree->left = malloc(sizeof(p_node*));
  tree->right = malloc(sizeof(p_node*));
  tree->back = back;
}
