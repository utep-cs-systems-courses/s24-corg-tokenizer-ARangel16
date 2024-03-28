#include "tokenizer.h"
#include "stdio.h"
#include "stdlib.h"


int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}//end of function


int non_space_char(char c){
  
  //invert return of space_char
  if(space_char(c) == 0){
    return 1;
  }

  return 0;
}//end of function

char *token_start(char *str){
  //loop until pointer *str null terminator
  while(*str){
    if(space_char(*str)){
      str++;
    }
    else{
      return str;
    }
  }
  return 0;

}//end of function


char *token_terminator(char *token){
  while(*token){
    if(non_space_char(*token)){
      token++;
    }
    else{
      return token;
    }
  }
  return 0;
  
}//end of function

int count_tokens(char *str) {

  char *s;

  char *t;

  int count = 0;



  while(*str) {

    s = token_start(str);

    t = token_terminator(s);

    if( !(s==0) ) {

      count++;

    }


    if (t==NULL) {

      return count;

    }

    str=t;

  }

}//end of function

char *copy_str(char *inStr, short len) {

  char *newStr = (char *)malloc((len+1)*sizeof(char));

  for(int i=0;i<len;i++) {

    newStr[i] = inStr[i];

  }

  newStr[len]='\0';

  return newStr;

}
char **tokenize(char* str){

  char **tokensOfWord=(char**)malloc(100*sizeof(char*));

  if (tokensOfWord == NULL) { exit(1); }



  char *token;

  char *t;

  int i = 0;

  int lenStr;

  int token_count = count_tokens(str);

  while (i < token_count) {

    token = token_start(str);

    t = token_terminator(token);

    lenStr = 0;

    while (token[lenStr] !=' ') {

      lenStr++;

    }

    tokensOfWord[i] = (char *)malloc((lenStr+1)*sizeof(char));

    tokensOfWord[i] = copy_str(token, lenStr);

    str = t;

    i++;

  }
  tokensOfWord[token_count] = NULL;
  return tokensOfWord;
}
//last method!
void print_tokens(char **tokens) {

  for(int i = 0; tokens[i] != NULL; i++) {

    printf("%s\n", tokens[i]);

  }

}


void free_tokens(char **tokens) {

  for(int i = 0; tokens[i]!= NULL; i++) {

    free(tokens[i]);

  }

  free(tokens);

}
