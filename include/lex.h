#pragma once

typedef struct token_s token;
typedef enum token_type_e token_type;

enum token_type_e {NUL, SOH, STX, ETX, EOT, ENQ, ACK, BEL, BS, HT, LF, VT,
	FR, CR, SO, SI, DLE, DC1, DC2, DC3, DC4, NAK, SYN, ETB, CAN, EM,
	SUB, ESC, FS, GS, RS, US, SPACE, EXCLAM, QUOTE, HASH, DOLLAR, PERCENT,
	AMPER, APOST, LPAREN, RPAREN, ASTER, PLUS, COMMA, MINUS, DOT, SLASH,
	ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, COLON,
	SCOLON, LESS, EQUAL, GREATER, QUESTION, AT, A_U, B_U, C_U, D_U, E_U, F_U,
	G_U, H_U, I_U, J_U, K_U, L_U, M_U, N_U, O_U, P_U, Q_U, R_U, S_U, T_U, U_U,
	V_U, W_U, X_U, Y_U, Z_U, A_L, B_L, C_L, D_L, E_L, F_L, G_L, H_L, I_L, J_L,
	K_L, L_L, M_L, N_L, O_L, P_L, Q_L, R_L, S_L, T_L, U_L, V_L, W_L, X_L, Y_L,
	Z_L, LBRACE, PIPE, RBRACE, TILDA, DEL, FUNC_NAME, VAR_NAME, DATA_TYPE, NUMBER}; // ADD MORE WHENEVER

struct token_s {
	token_type id;
	char** args;
	token* next;
};

typedef token* token_ll;
