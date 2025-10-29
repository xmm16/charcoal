#include "lex.h"
#include <stdio.h>

int main(int argc, char** argv){
  size_t code_lex_index;
  token_ll lexed_code = lex(argv[1], &code_lex_index);
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
}
