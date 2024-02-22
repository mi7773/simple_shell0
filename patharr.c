#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * patharr - draft
 * Return: draft
 */
char **patharr()
{
	char **pa, *str, *gpr = getpath();
	int i, j, k;

	i = 0;
	j = 0;
	while (gpr[i])
	{
		if (gpr[i] == ':')
		{
			j++;
		}
		i++;
	}
	pa = (char **) malloc(sizeof(char *) * (j + 2));
	str = strtok(gpr, ":");
	i = 0;
	while (str)
	{
		pa[i] = str;
		str = strtok(0, ":");
		i++;
	}
	pa[i] = 0;

	return (pa);
}
