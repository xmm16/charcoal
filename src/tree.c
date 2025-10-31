#include "tree.h"
#include "lex.h"
#include <stddef.h>
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

// make sure to split the following up into organized code files if possible
void equals(p_node* code_tree, token_ll code, size_t code_length, size_t index){
  p_node_t type;
  p_node_r rank;
  size_t start;
  size_t end;

  p_node_t type_l;
  p_node_r rank_l;
  size_t start_l;
  size_t end_l;

  p_node_t type_r;
  p_node_r rank_r;
  size_t start_r;
  size_t end_r;

  if (index + 2 < code_length && token_ll_index(code, index + 2)->id == PAREN){
    
  }

  insert_tree(code_tree->left, code_tree, type, rank, start, end); // main branch
  insert_tree(code_tree->left->left, code_tree->left, type_l, rank_l, start_l, end_l); // left side of equation branch
  insert_tree(code_tree->left->right, code_tree->left, type_r, rank_r, start_l, end_l); // right side of equation branch

  // FOR EACH COMPLEX BRANCH, RUN TREE ENGINE ON IT AGAIN. IF LITERAL, NOT NECESSARY
}

void tree_engine(p_node* code_tree, token_ll code, size_t code_length){
  p_node* local_code_tree = code_tree;
  for (int i = 0; i < code_length; i++){
    switch (token_ll_index(code, i)->id) {
      case '=':
        equals(local_code_tree, code, code_length, i);
        local_code_tree = local_code_tree->right;
        break;
      default:
        break;
    }
  }

}
