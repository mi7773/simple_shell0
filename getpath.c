#include "main.h"

/**
 * getpath - draft
 * Return: draft
 */
char *getpath(void)
{
	int i, j;

	i = 0;
	while (environ)
	{
		j = 0;
		while (environ[i][j] == "PATH"[j])
		{
			j++;
			if (environ[i][j] == '=')
			{
				return (&environ[i][j + 1]);
			}
		}
		i++;
	}
}
