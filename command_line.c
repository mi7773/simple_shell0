#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include <sys/wait.h>

int main(void)
{
	char *cmd = NULL, *delim = " \n";
	char **cmd_tokens = NULL;
	ssize_t nread = 0;
	size_t n = 0, i = 0;
	int status;
	pid_t pid= 0;

	do {
		printf("$ ");
		nread = getline(&cmd, &n, stdin);
		cmd_tokens = make_tokens(cmd, delim);
		if (cmd_tokens == NULL)
		{
			fprintf(stderr, "Unexpected error\n");
			exit(EXIT_FAILURE);
		}

		pid = fork();
		if (pid == -1)
			fprintf(stderr, "Error failed to fork\n");
		else if (pid == 0)
			execve(cmd_tokens[0], cmd_tokens, NULL);
		else
			wait(&status);
	} while (nread != EOF);

	while (cmd_tokens != NULL)
	{
		free(cmd_tokens[i]);
		i++;
	}
	free(cmd_tokens);
	free(cmd);
	exit(EXIT_SUCCESS);
}
