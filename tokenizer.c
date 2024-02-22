#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t tokenize(char *str, char *delim)
{
	size_t words = 0;

	if (strtok(str, delim))
		words++;
	while (strtok(NULL, delim))
		words++;

	return (words);
}

char **make_tokens(char *str, char *delim)
{
	char **tokens = NULL;
	char prev_char = '\0';
	size_t arr_iter = 0, arr_size = 0;
	size_t str_iter, str_size = 0;

	str_size = strlen(str);
	if (str_size == 0)
	{
		fprintf(stderr, "Error command size: [%ld]\n", str_size);
		return (NULL);
	}

	arr_size = tokenize(str, delim);
	if (arr_size == 0)
	{
		fprintf(stderr, "Error can't tokenize str [%s]\n", str);
		return (NULL);
	}

	tokens = malloc(sizeof(char *) * (arr_size + 1));
	if (tokens == NULL)
	{
		fprintf(stderr, "Error can't use malloc\n");
		return (NULL);
	}

	for (str_iter = 0; str_iter < str_size; str_iter++)
	{
		if (str[str_iter] != '\0' && prev_char == '\0')
		{
			tokens[arr_iter] = str + str_iter;
			arr_iter++;
		}
		prev_char = str[str_iter];
	}
	tokens[arr_iter] = NULL;
	return (tokens);
}
