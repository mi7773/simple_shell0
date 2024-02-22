#include <stdio.h>
#include <unistd.h>

/**
* main - runs code
* Return: 0
*/
int main(void)
{
	int a = 3, b = 5;
	int mult = a * b;
	pid_t pproc_id;

	pproc_id = getppid();

	printf("The result of a(%d) * b(%d) is: %d\n", a, b, mult);
	printf("This parent process ID is: %u\n", pproc_id);
	return (0);
}
