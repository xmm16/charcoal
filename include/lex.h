#ifndef LEX
#define LEX
#include <stddef.h>
#include <stdlib.h>

typedef struct token_s token;
typedef enum token_type_e token_type;

enum token_type_e {NUL, EQUAL_SLASH, EQUAL_ARROW, EQUAL_EQUAL, EOT, ENQ, ACK, BEL, BS, HT, LF, VT,
	FR, CR, SO, SI, DLE, DC1, DC2, DC3, DC4, NAK, SYN, ETB, CAN, EM,
	SUB, ESC, FS, GS, RS, US, SPACE, EXCLAM, QUOTE, HASH, DOLLAR, PERCENT,
	AMPER, APOST, PAREN, RPAREN, ASTER, PLUS, COMMA, MINUS, DOT, SLASH,
	ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, COLON,
	SCOLON, LESS, EQUAL, GREATER, QUESTION, AT, A_U, B_U, C_U, D_U, E_U, F_U,
	G_U, H_U, I_U, J_U, K_U, L_U, M_U, N_U, O_U, P_U, Q_U, R_U, S_U, T_U, U_U,
	V_U, W_U, X_U, Y_U, Z_U, LBRACKET, BACKSLASH, RBRACKET, CARET, UNDERSCORE, BTICK,
  A_L, B_L, C_L, D_L, E_L, F_L, G_L, H_L, I_L, J_L, K_L, L_L, M_L, N_L, O_L, 
  P_L, Q_L, R_L, S_L, T_L, U_L, V_L, W_L, X_L, Y_L, Z_L, LBRACE, PIPE, RBRACE,
  TILDA, DEL, WORD, INT, FLOAT}; // ADD MORE WHENEVER

typedef token* token_ll;

struct token_s {
	token_type id;
	char* args;
	token* next;
	token* back;
	token_ll carry;
};

token_ll create_token_ll();
void token_ll_add_next(token_ll to_push_to, token_ll back, token_type id, char* args);
token_ll token_ll_index(token_ll to_get_index_of, size_t index);
token* token_from_ll(token_ll to_get_value_of, size_t index);
token_ll lex(char* raw_code, size_t* code_lex_index_param);
#endif
