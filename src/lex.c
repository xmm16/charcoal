#include "lex.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_number(char symbol){
        return (symbol >= 48 && symbol <=57) || (symbol == 46);
}

bool letter_or_number(char symbol){
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

token_ll lex(char* raw_code, size_t* code_lex_index_param){
	token_ll code = create_token_ll();
	size_t code_lex_index = 0;
	
	for (int i = 0; i < strlen(raw_code); i++){
    if (strlen(raw_code) > i + 2){
      char* two_char_compare = substring(raw_code, i, i+2);

      if (strcmp(two_char_compare, "//") == 0){
        while (raw_code[i] != '\n') i++;
        continue;
      }
      
      if (strcmp(two_char_compare, "/*") == 0){
        while (true){
          char* until_end_comment = substring(raw_code, i, i+2);
          if (strcmp(until_end_comment, "*/") == 0) break;
          free(until_end_comment);
          i++;
          continue;
        }
      }
		  
      free(two_char_compare);
    }

		if (raw_code[i] == '"'){
      if (strlen(raw_code) > i + 1){
        size_t start_quote = i + 1;

        while (raw_code[i] != '"' && strlen(raw_code) > i) i++;

        char* to_add = substring(raw_code, start_quote, i);
        token_ll_add_next(token_ll_index(code, code_lex_index), QUOTE, to_add);
        code_lex_index++;
        continue;
      }
    }

    // first check for space or other breaker. then, if it is, first try to
    // see if the word is a variable by checking if the first character is a number.
    // then if it is, define it as a number and add the token.
    // but if it isn't, define it as a word and add the token.
    // if any characters are a symbol or a space, that's when you break out.
    // one period shouldn't count if it's a number, but multiple should.

    while (raw_code[i] == ' ' || raw_code[i] == '\t' || raw_code[i] == '\n') continue;

    size_t multi_char_arg_size = 1;
    char* multi_char_arg = malloc(multi_char_arg_size);
    multi_char_arg[0] = '\0';

    token_type type = INT;
      
    while (is_number(raw_code[i])){ // is_number includes periods
      if (strlen(multi_char_arg) + 2 > multi_char_arg_size){
        multi_char_arg_size *= 2;
        multi_char_arg = (char*) realloc(multi_char_arg, multi_char_arg_size);
      }
      if (raw_code[i] == '.') type = FLOAT;

      multi_char_arg[strlen(multi_char_arg) - 1] = raw_code[i];
      multi_char_arg[strlen(multi_char_arg)] = '\0';
      i++;
    }

    if (multi_char_arg[0] == '\0') type = WORD;

    while (letter_or_number(raw_code[i])){
      if (strlen(multi_char_arg) + 2 > multi_char_arg_size){
        multi_char_arg_size *= 2;
        multi_char_arg = (char*) realloc(multi_char_arg, multi_char_arg_size);
      }
      
      multi_char_arg[strlen(multi_char_arg) - 1] = raw_code[i];
      multi_char_arg[strlen(multi_char_arg)] = '\0';
      i++;
    }

    if (multi_char_arg[0] != '\0'){
      token_ll_add_next(token_ll_index(code, code_lex_index), type, multi_char_arg);
      code_lex_index++;
    }

    token_ll_add_next(token_ll_index(code, code_lex_index), (token_type) raw_code[i], NULL);
    code_lex_index++;
	}

  *code_lex_index_param = code_lex_index;
  return code;
}
