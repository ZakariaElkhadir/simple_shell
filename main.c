#include "shell.h"

int main (int ac, char **argv)
{
    char *line = NULL;
    char **command = NULL;
    int status = 0, i;
    (void) ac;
    (void) argv;

    do
    {
        line = read_command();
        /*stop the program*/
        if (line == NULL)
        {
            if(isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "\n", 2);
            return (status);
        }
        
      command = token(line);
      if(!command)
      continue;
      
      for ( i = 0; command[i]; i++)
      {

      printf("%s\n", command[i]);

      free(command[i]), command[i] = NULL;
        /*status = _execute(command , argv);
        */
      }
      free(command);
      command = NULL;
    }while (1);
    
}