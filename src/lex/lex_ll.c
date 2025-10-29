#include "lex.h"
#include <stdlib.h>

token_ll create_token_ll(){
	token_ll result;
	result = malloc(sizeof(token_ll));
	return result;
}

void token_ll_add_next(token_ll to_push_to, token_type id, char* args){ 
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

/* EXAMPLE USAGE:

#include <stdio.h>


int main(){
	token_ll code = create_token_ll();
	token_ll_add_next(token_ll_index(code, 0), A_U, NULL);
	token_ll_add_next(token_ll_index(code, 1), D_U, NULL);
	token_ll_add_next(token_ll_index(code, 2), F_U, NULL);
	printf("%d\n", token_from_ll(code, 2)->id);

}

*/
