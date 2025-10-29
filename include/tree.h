#ifndef TREE
#define TREE
#include <stddef.h> // I forgot why I chose to include this everywhere
                    // but I'm gonna assume it's important, soo I won't be
                    // removing it.

typedef struct p_node_s p_node;
typedef enum p_node_type_e p_node_t;
typedef enum p_node_rank_e p_node_r;

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
  COMPLEX, /* literal means that something is only one layer, like a number,
              while complex means multiple layers, like an expression with a variable */
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

#endif
