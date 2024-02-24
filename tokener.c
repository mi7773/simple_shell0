#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
* tokenize - changes a string to tokens
* @lineptr: read line from getline function
*
* Return: array of strings contains tokens form lineptr
*/
char **tokenize(char *lineptr)
{
	char *tkn = NULL;
	char *delim = " \n";
	char **tokens = NULL;
	int i = 0, tkn_num = 1, tkn_iter = 0;

	while (lineptr[i] != '\0')
	{
		if (lineptr[i] == ' ')
			tkn_num++;
		i++;
	}

	tokens = malloc(sizeof(char *) * (tkn_num + 1));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}

	tkn = strtok(lineptr, delim);
	while (tkn != NULL && tkn_iter < tkn_num)
	{
		tokens[tkn_iter] = tkn;
		tkn_iter++;
		tkn = strtok(NULL, delim);
	}
	tokens[tkn_iter] = NULL;

	return (tokens);
}
