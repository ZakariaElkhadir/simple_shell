#include "shell.h"
char *read_command(void)
{
    char *line = NULL;
           size_t len = 0;
           ssize_t nread;
           if(isatty(STDIN_FILENO))
           write(STDERR_FILENO, "@ ", 2);
           /*getline will calculate the number of characters*/
           nread = getline(&line, &len, stdin);
           if (nread == -1)
           {
            free(line);
            return (NULL);
           }
        return (line);
}
