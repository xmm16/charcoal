#ifndef TREE
#define TREE
#include <stddef.h> // I forgot why I chose to include this everywhere
                    // but I'm gonna assume it's important, soo I won't be
                    // removing it.

typedef struct p_node_s p_node;
typedef enum p_node_type_e p_node_t;
typedef enum p_node_rank_e p_node_r;


enum p_node_type_e {NUL_p, SOH_p, STX_p, ETX_p, EOT_p, ENQ_p, ACK_p, BEL_p, BS_p, HT_p, LF_p, VT_p,
	FR_p, CR_p, SO_p, SI_p, DLE_p, DC1_p, DC2_p, DC3_p, DC4_p, NAK_p, SYN_p, ETB_p, CAN_p, EM_p,
	SUB_p, ESC_p, FS_p, GS_p, RS_p, US_p, SPACE_p, EXCLAM_p, QUOTE_p, HASH_p, DOLLAR_p, PERCENT_p,
	AMPER_p, APOST_p, LPAREN_p, RPAREN_p, ASTER_p, PLUS_p, COMMA_p, MINUS_p, DOT_p, SLASH_p,
	ZERO_p, ONE_p, TWO_p, THREE_p, FOUR_p, FIVE_p, SIX_p, SEVEN_p, EIGHT_p, NINE_p, COLON_p,
	SCOLON_p, LESS_p, EQUAL_p, GREATER_p, QUESTION_p, AT_p, A_U_p, B_U_p, C_U_p, D_U_p, E_U_p, F_U_p,
	G_U_p, H_U_p, I_U_p, J_U_p, K_U_p, L_U_p, M_U_p, N_U_p, O_U_p, P_U_p, Q_U_p, R_U_p, S_U_p, T_U_p, U_U_p,
	V_U_p, W_U_p, X_U_p, Y_U_p, Z_U_p, LBRACKET_p, BACKSLASH_p, RBRACKET_p, CARET_p, UNDERSCORE_p, BTICK_p,
  A_L_p, B_L_p, C_L_p, D_L_p, E_L_p, F_L_p, G_L_p, H_L_p, I_L_p, J_L_p, K_L_p, L_L_p, M_L_p, N_L_p, O_L_p, 
  P_L_p, Q_L_p, R_L_p, S_L_p, T_L_p, U_L_p, V_L_p, W_L_p, X_L_p, Y_L_p, Z_L_p, LBRACE_p, PIPE_p, RBRACE_p,
  TILDA_p, DEL_p, PROGRAM_p, STATEMENT_p, PAREN_EXPR_p, EXPR_p, ASSIGN_p, CALL_p, SEQ_p, VEC_p, VAR_p, INT_p, FLOAT_p}; // ADD MORE WHENEVER

enum p_node_rank_e {
  COMPLEX, /* literal means that something is only one layer_p, like a number_p,
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
