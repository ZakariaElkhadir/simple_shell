#include "shell.h"

int main(int argc, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	(void) argc;

	do {
		line = read_command();
		/*stop the program*/
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 2);
			return (status);
		}

		command = token(line);
		if (!command)
			continue;

		status = _execute(command, argv);


	} while (1);

}
