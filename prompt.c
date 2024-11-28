#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2024];

char *readline(char *prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2024, stdin);
  char *cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

void add_history(char *unused) {}

#else
#include <editline/history.h>
#include <editline/readline.h>
#endif

int main(int argc, char **argv) {
  puts("Lispy version 0.0.0.0.1");
  puts("2024-11-27");
  puts("Press Ctrl+c to exit\n");

  while (1) {
    /* Output our prompt and get input */
    char *input = readline("shisp> ");
    add_history(input);

    printf("The user say: %s\n", input);
    free(input);
  }

  return 0;
}
