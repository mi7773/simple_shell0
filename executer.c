#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
* execute - execute a program
* @tokens: tokens
*/
void execute(char **tokens)
{
	pid_t pid = 0;
	int rexec = 0, wstatus;

	pid = fork();
	if (pid == -1)
	{
		write(STDERR_FILENO, "Error: can't fork\n", 18);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		rexec = execve(tokens[0], tokens, NULL);
		if (rexec == -1)
		{
			write(STDERR_FILENO, "Error: can't execute file\n", 26);
			return;
		}
	}
	else
		wait(&wstatus);
}
