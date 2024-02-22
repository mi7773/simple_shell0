#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <stdio.h>

/**
 * coarr - draft
 * @buf: draft
 * Return: draft
 */
char **coarr(char *buf)
{
	char **ca, *str;
	int i, j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (buf[i] == ' ')
		{
			j++;
		}
		i++;
	}
	ca = (char **) malloc(sizeof(char *) * (j + 2));
	str = strtok(buf, "\n");
	str = strtok(str, " ");
	i = 0;
	while (str)
	{
		ca[i] = str;
		printf("%s\n", ca[i]);
		str = strtok(0, " ");
		i++;
	}
	ca[i] = 0;

	return (ca);
}
