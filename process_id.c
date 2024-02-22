#include <unistd.h>
#include <stdio.h>

/**
* main - runs code
* Return: 0
*/
int main(void)
{
	int a = 3, b = 4;
	int sum = a + b;
	pid_t proc_id;

	proc_id = getpid();

	printf("Sum of a(%d) and b(%d) is: %d\n", a, b, sum);
	printf("This process ID was: %u\n", proc_id);
	return (0);
}
