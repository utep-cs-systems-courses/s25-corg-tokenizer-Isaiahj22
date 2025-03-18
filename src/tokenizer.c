#include "stdlib.h"
#include "stdio.h"
#include "tokenizer.h"


int space_char(char c)
{
  return (c == ' ') || (c == '\t') ? 1 : 0;
}

int non_space_char(char c)
{
  return ((int)c >= 33) ? 1 : 0;
}

char *token_start(char *str) 
{
  while(*str != '\0' && space_char(*str)){
    str++;
  }
  return str;

}

char *token_terminator(char *str)
{

  while(*str != '\0' && non_space_char(*str)){
    str++;
  }
  return str;

}

int count_tokens(char *str)
  {
  int count = 0;
  
  while(*str != '\0')
    {
      str = token_start(str);
      if (*str == '\0') break;

      count++;
      str = token_terminator(str);
    }

  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, int len)
{
  int sindex = 0;
  char *scopy = malloc((len + 1) * sizeof(char)), c;
  do {
    c = *(scopy + sindex) = *(inStr+sindex);
    sindex++;
  } while (non_space_char(c));

  return scopy;

}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/

char **tokenize(char *str)
{
  int numWords = count_tokens(str);
  char **tokens = malloc(numWords * sizeof(char *));

  char *start = token_start(str);
  for(int i = 0; i < numWords; i++){
    
    char *end = token_terminator(start);
    int wordLen = end - start;
    
    tokens[i] = copy_str(start, wordLen);

    start = token_start(end);
  }

  tokens[numWords] = 0;
  return tokens;

}

void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != 0){
    printf("Word %d: %s\n", i + 1, tokens[i]);
    i++;
  } 

}

void free_tokens(char **tokens)
{

  int i = 0;
  while(tokens[i] != 0){
    free(tokens[i]);
    i++;
  } 
  free(tokens);

}
