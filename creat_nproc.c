#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* main - runs code
* Return: 0
*/
int main(void)
{
	int a = 2, b = 3, c = 4, status;
	pid_t ppid, child_pid, my_pid;

	child_pid = fork();
	my_pid = getpid();
	ppid = getppid();

	if (child_pid == -1)
	{
		perror("Error occured");
		return (0);
	}

	if (child_pid == 0)
	{
		printf("I am in the frok and I am a new child process.\n");
		printf("ppid: %u, pid: %u\n", ppid, my_pid);
	}
	else
	{
		wait(&status);
		printf("I am out of fork and I am the parent process.\n");
		printf("ppid: %u, pid: %u\n", ppid, my_pid);
	}
	return (0);
}
