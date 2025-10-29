#include "lex.h"
#include <stdio.h>

int main(int argc, char** argv){
  size_t code_lex_index;
  token_ll lexed_code = lex(argv[1], &code_lex_index);
  printf("code_lex_index = %zu\n", code_lex_index);

  for (int i = 0; i < code_lex_index; i++){
    printf("%d\n", token_from_ll(lexed_code, i)->id);
  }
}
