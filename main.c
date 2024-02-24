#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	char *line = NULL;
	char **tokens = NULL;
	size_t ninput = 0;
	ssize_t nread = 0;
	pid_t pid = 0;
	int rexec = 0, wstatus;

	do {
		write(STDOUT_FILENO, "$ ", 2);
		nread = getline(&line, &ninput, stdin);
		if (nread == -1)
			break;

		if (line == NULL)
		{
			putchar('\n');
			continue;
		}

		tokens = tokenize(line);
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
				continue;
			}
		}
		else
			wait(&wstatus);
	} while (1);
	putchar('\n');
	free(tokens);
	free(line);

	exit(EXIT_SUCCESS);
}
