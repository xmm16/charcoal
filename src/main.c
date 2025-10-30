#include "lex.h"
#include "tree.h"
#include <stdio.h>

int main(int argc, char** argv){
  size_t code_lex_index;
  token_ll lexed_code = lex(argv[1], &code_lex_index);

  /* PRINT LEX
    for (int i = 0; i < code_lex_index; i++){
      int id = token_from_ll(lexed_code, i)->id;
      switch (id){
        case 128:
          printf("id: WORD\narg: %s\n", token_from_ll(lexed_code, i)->args);
          break;

        case 129:
          printf("id: INT\narg: %s\n", token_from_ll(lexed_code, i)->args);
          break;

        case 130:
          printf("id: FLOAT\narg: %s\n", token_from_ll(lexed_code, i)->args);
          break;

        default:
          printf("id: (symbol) %c\narg: %s\n", id, token_from_ll(lexed_code, i)->args);
      }

      printf("\n");
    }
  //

  *//*
  enum p_node_type_e {
  PROGRAM,
  STATEMENT,
  PAREN_EXPR,
  EXPR,
  ASSIGN,
  CALL,
  SEQ,
  VEC
};

enum p_node_rank_e {
  COMPLEX,
  LITERAL
};

struct p_node_s {
  p_node_t type;
  p_node_r rank;
  p_node* back;
  p_node* next;
};

  p_node create_tree(p_node_t type, p_node_r rank);
  void insert_tree(p_node* tree, size_t index, p_node_t type, p_node_r rank);
  p_node* access_tree(p_node* tree, size_t index);

  p_node code_tree = create_tree(PROGRAM, COMPLEX);
  insert_tree(&code_tree, 1, STATEMENT, COMPLEX);
  insert_tree(&code_tree, 2, CALL, LITERAL);

  printf("%d\n", access_tree(&code_tree, 2)->type);
  */

//  p_node code_tree = create_tree(PROGRAM_p, COMPLEX, 0, code_lex_index);
//  p_node* local_code_tree = &code_tree;

//    token* current_token = token_from_ll(lexed_code, i);

    /*
    This is the idea:
     So for each type, so for + and - and also function calls and things, we use
     functions to create a new tree for that group, like an add function and a subtract
     function, and a call processing function (all variables are unsigned iXX types, and
     remember, bitcasting doesn't happen in the actual assembly, so still optimized).

     Then the trees are merged using a manual connection. It should work fine, I think.
    */
}
