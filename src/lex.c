#include "lex.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
#include "lex.h"
#include <stdlib.h>

token_ll code;

token_ll create_token_ll(){
        token_ll result;
        result = malloc(sizeof(token_ll));
        return result;
}

void token_ll_add_next(token_ll to_push_to, token_type id, char** args){ 
        to_push_to->id = id;
        to_push_to->args = args;
        to_push_to->next = malloc(sizeof(token));
}

token_ll token_ll_index(token_ll to_get_index_of, size_t index){
        token_ll result = to_get_index_of;
        for (int i = 0; i < index; i++) {
                result = (token_ll) (result->next);
        }

        return result;
}

token* token_from_ll(token_ll to_get_value_of, size_t index){
        return (token*) token_ll_index(to_get_value_of, index);
}

EXAMPLE USAGE:

#include <stdio.h>


int main(){
        code = create_token_ll();
        token_ll_add_next(token_ll_index(code, 0), A_U, NULL);
        token_ll_add_next(token_ll_index(code, 1), D_U, NULL);
        token_ll_add_next(token_ll_index(code, 2), F_U, NULL);
        printf("%d\n", token_from_ll(code, 1)->id);

}

*/

bool allowed_in_var_name(char symbol){
        return (symbol >= 48 && symbol <=57) || (symbol >= 65 && symbol <= 122);
}

char* strip(char* original){
        size_t displacement = 0;

        while (original[displacement] == ' ') displacement++;
        while (original[strlen(original) - 1] == ' ') original[strlen(original) - 2] = '\0';

        return original + displacement;
}

char* substring(char* original, size_t start, size_t end){ // needs to be freed
        char* result = malloc(end - start + 1);
        result[end - start] = '\0';
        
        for (int i = 0; i < end - start; i++){
                result[i] = original[i + start];
        }
        
        return strip(result);
}

/*
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
*/
token_ll lex(char* raw_code){
	code = create_token_ll();
	code_lex_index = 0;
	
	for (int i = 0; i < strlen(raw_code); i++){
		char* two_char_compare = substring(raw_code, i, i+2)

		if (strcmp(two_char_compare, "//") == 0){
			while (raw_code[i] != '\n') i++;
		}
		
		if (strcmp(two_char_compare, "/*") == 0){
			while (true){
				char* until_end_comment = substring(raw_code, i, i+2);
				
				if (strcmp(until_end_comment, "*/") == 0) break;

				free(until_end_comment);
				i++;
			}
		}

		if (raw_code[i] == '"'){
			size_t start_quote = i + 1;

			while (raw_code[i] != '"') i++;

			char* to_add = substring(raw_code, start_quote, i);
			char** to_add_ptr = malloc(sizeof(to_add));
        		token_ll_add_next(token_ll_index(code, code_lex_index), QUOTE, to_add_ptr);
		}

		

		free(two_char_compare);
		
	}
}
