#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "main.h"

/**
 * nactive - draft
 * Return: draft
 */
int nactive(void)
{
	char *bufcwd = 0;
	size_t size;
	char buf[128], **ca, **pa, *cwd = getcwd(bufcwd, size);
	struct stat st;

	read(STDIN_FILENO, buf, sizeof(buf));
	ca = coarr(buf);
	pa = patharr();
	if (stat(ca[0], &st) == 0)
	{
		execve(ca[0], ca, environ);
	}
	free(ca);
	free(pa);

	return (0);
}
