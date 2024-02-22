#include <unistd.h>
#include "main.h"

/**
 * main - draft
 * Return: draft
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		active();
	}
	else
	{
		nactive();
	}

	return (0);
}
