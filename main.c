#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
* main - runs code
* Return: exit status
*/
int main(void)
{
	char *line = NULL;
	char **tokens = NULL;
	size_t ninput = 0;
	ssize_t nread = 0;

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
		execute(tokens);
	} while (1);
	putchar('\n');
	free(tokens);
	free(line);

	exit(EXIT_SUCCESS);
}
