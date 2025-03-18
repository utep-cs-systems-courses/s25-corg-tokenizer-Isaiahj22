#include <stdio.h>
#include <stdlib.h>
#include "history.h" // project-related declarations
#include "tokenizer.h"

#define MAXSIZE 100

int main() 
{
  puts("Welcome!");
  puts("Commands: '!##': Get saved string, '&': Clear history, '>': Print history, '@': Exit Program  ");
  List *hist = init_history();
  while (1) { // Infinite while loop
    fputs("$ ", stdout);
    fflush(stdout);    /* stdout only flushes automatically on \n */
    char *userInput = malloc(MAXSIZE * sizeof(char));
    int len = 0;
    char c;
    while ((c = getchar() ) != EOF && c != '\n' && len < MAXSIZE-1){
      userInput[len++] = c;

      if(c == '@')
	goto done;
    }
      

    if(userInput[0] == '>'){
      print_history(hist);
    }
      
    else if(userInput[0] == '!'){
      char *num = userInput + 1;
      int number = atoi(num);
      printf("ID: %d String: %s\n",number, get_history(hist, number));

    }
    else if(userInput[0] == '&'){
      free_history(hist);
    }
    else{
      add_history(hist,userInput);
      char **toks = tokenize(userInput);
      print_tokens(toks);
      free_tokens(toks);
      putchar('\n');
    }
 }
      
 done:
  return 0;
  
}
