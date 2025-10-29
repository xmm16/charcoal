#ifndef TREE
#define TREE
#include <stddef.h> // I forgot why I chose to include this everywhere
                    // but I'm gonna assume it's important, soo I won't be
                    // removing it.

typedef struct p_node_s p_node;
typedef enum p_node_type_e p_node_t;
typedef enum p_node_rank_e p_node_r;


enum p_node_type_e {NUL, SOH, STX, ETX, EOT, ENQ, ACK, BEL, BS, HT, LF, VT,
	FR, CR, SO, SI, DLE, DC1, DC2, DC3, DC4, NAK, SYN, ETB, CAN, EM,
	SUB, ESC, FS, GS, RS, US, SPACE, EXCLAM, QUOTE, HASH, DOLLAR, PERCENT,
	AMPER, APOST, LPAREN, RPAREN, ASTER, PLUS, COMMA, MINUS, DOT, SLASH,
	ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, COLON,
	SCOLON, LESS, EQUAL, GREATER, QUESTION, AT, A_U, B_U, C_U, D_U, E_U, F_U,
	G_U, H_U, I_U, J_U, K_U, L_U, M_U, N_U, O_U, P_U, Q_U, R_U, S_U, T_U, U_U,
	V_U, W_U, X_U, Y_U, Z_U, LBRACKET, BACKSLASH, RBRACKET, CARET, UNDERSCORE, BTICK,
  A_L, B_L, C_L, D_L, E_L, F_L, G_L, H_L, I_L, J_L, K_L, L_L, M_L, N_L, O_L, 
  P_L, Q_L, R_L, S_L, T_L, U_L, V_L, W_L, X_L, Y_L, Z_L, LBRACE, PIPE, RBRACE,
  TILDA, DEL, PROGRAM, STATEMENT, PAREN_EXPR, EXPR, ASSIGN, CALL, SEQ, VEC, VAR, INT, FLOAT}; // ADD MORE WHENEVER

enum p_node_rank_e {
  COMPLEX, /* literal means that something is only one layer, like a number,
              while complex means multiple layers, like an expression with a variable */
  LITERAL
};

struct p_node_s {
  p_node_t type;
  p_node_r rank;
  p_node* back;
  size_t start;
  size_t end;
  p_node* left;
  p_node* right;
};

p_node create_tree(p_node_t type, p_node_r rank, size_t start, size_t end);
void insert_tree(p_node* tree, p_node* back, p_node_t type, p_node_r rank, size_t start, size_t end);
//                   ^^^^ for example: insert_tree(&(code_tree.left->left->right), &(code_tree.left->left), EXPR, COMPLEX, i, i+2);

#endif
