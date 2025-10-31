#include "tree.h"
#include "lex.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

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
void equals(p_node* code_tree, p_node* back, token_ll code, size_t code_length, size_t index){
  p_node_t type = ASSIGN_p;
  p_node_r rank = COMPLEX;
  size_t start;
  size_t end;

  size_t start_l;
  size_t end_l;

  size_t start_r;
  size_t end_r;

  if (index + 2 < code_length && token_ll_index(code, index + 2)->id == PAREN){
    start_r = index + 1;
    end_r = index + 3;
  } else {
    start_r = index + 1;
    end_r = index + 2;
  }

  if (index - 2 >= 0 && index - 2 < index && token_ll_index(code,index - 1)->id == PAREN && token_ll_index(code, index - 2)->id == WORD){
    start_l = index - 2;
    end_l = index;
  } else {
    start_l = index - 1;
    end_l = index;
  }

  insert_tree(code_tree, back, type, rank, start_l, end_r); // main branch
  tree_engine(code_tree->left, token_ll_index(code, start_l), end_l - index);
  tree_engine(code_tree->right, token_ll_index(code, start_r), end_r - index);
  // FOR EACH COMPLEX BRANCH, RUN TREE ENGINE ON IT AGAIN
}

void def(p_node* code_tree, p_node* back, token_ll code, size_t code_length, size_t index){
  p_node_t type = 'D';
  p_node_r rank = LITERAL;
  size_t start = index;
  size_t end = index + 1;

  insert_tree(code_tree, back, type, rank, start, end); // main branch
  // FOR EACH COMPLEX BRANCH, RUN TREE ENGINE ON IT AGAIN
}

void tree_engine(p_node* code_tree, token_ll code, size_t code_length){ // 
  p_node* local_code_tree = code_tree;
  uint8_t is_literal = 1;
  for (int i = 0; i < code_length; i++){
    switch (token_ll_index(code, i)->id) {
      case '=':
        equals(local_code_tree, local_code_tree->back, code, code_length, i);
	is_literal = 0;
        break;
      default:
        break;
    }
  }
  if (is_literal) def(local_code_tree, local_code_tree->back, code, code_length, 0);
  // for (int i = 0; i < code_length; i++)
    // def(local_code_tree, local_code_tree->back, code, code_length, i);
}


