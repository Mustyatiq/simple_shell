#include "main.h"
/**
 * execArg - executes commands
 * command: command to execute
 * name: argv[0]
 */
void execArg(char **command, char *name)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return;
	}
	else if (pid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
			perror(name);
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}
