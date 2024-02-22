#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "main.h"

/**
 * active - draft
 * Return: draft
 */
int active(void)
{
	char *lineptr = 0, **ca = 0;
	size_t n = 0;
	struct stat st;
	pid_t frpid;
	int status;
	ssize_t glr;

	do {
		write(STDOUT_FILENO, "$ ", 2);
		glr = getline(&lineptr, &n, stdin);
		if (glr == -1)
		{
			break;
		}
		ca = coarr(lineptr);
		if (stat(ca[0], &st) == 0)
		{
			frpid = fork();
			if (frpid == -1)
			{
				return (1);
			}
			else if (frpid == 0)
			{
				execve(ca[0], ca, environ);
			}
			else
			{
				wait(&status);
			}
		}
	} while (1);
	free(lineptr);
	free(ca);

	return (0);
}
