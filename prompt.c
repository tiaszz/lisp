#include <stdio.h>
#include <stdlib.h>

#include <editline/realine.h>
#include <editline/history.h>

int main(int argc, char** argv) {
  puts("Lispy version 0.0.0.0.1");
  puts("Press Ctrl+c to exit\n");

  while (1) {
    /* Output our prompt and get input */
    char* input = realine("lispy> ");

    add_history(input);

    printf("No you're a %s", input);

    free(input);
  }
  return 0;
}
