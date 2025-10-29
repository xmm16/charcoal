#include "tree.h"
#include <stdlib.h>

p_node create_tree(p_node_t type, p_node_r rank){
  p_node result;
  result.type = type;
  result.rank = rank;
  result.next = malloc(sizeof(p_node*));
  result.back = NULL; 
  return result;
}

void insert_tree(p_node* tree, size_t index, p_node_t type, p_node_r rank){
  p_node* tree_at_index = tree;
  p_node* previous_tree;

  for (int i = 0; i < index; i++){
    tree_at_index = tree_at_index->next;
    if (i == index - 2) previous_tree = tree_at_index;
  }

  tree_at_index->type = type;
  tree_at_index->rank = rank;
  tree_at_index->next = malloc(sizeof(p_node*));
  tree_at_index->back = previous_tree;
}

p_node* access_tree(p_node* tree, size_t index){
  p_node* tree_at_index = tree;

  for (int i = 0; i < index; i++){
    tree_at_index = tree_at_index->next;
  }

  return tree_at_index;
}

