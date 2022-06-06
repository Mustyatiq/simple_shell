#include "main.h"
/**
 * main - prints a command
 * Return: number of characters read
 */
int main(int argc, char *argv[])
{
	char *command[2] = {NULL, NULL};
	int x, i, z, loop = 1;
	size_t length = 1024;

	z = argc - argc;
	while (loop == 1)
	{
		printf("$ ");
		x = getline(command, &length, stdin);

		if (x != -1)
		{
			for (i = z; command[0][i] != '\0'; i++)
			{
				if (command[0][i] == 10)
					command[0][i] = '\0';
			}
			if (_strcmp(command[0], "exit") != 0)
				execArg(command, argv[0]);
			else
				loop = 0;
		}
	}
	return (x);
}
