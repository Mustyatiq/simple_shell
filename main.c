#include "main.h"
/**
 * main - prints a command
 * Return: number of characters read
 */
int main(int argc, char *argv[])
{
	char *command[2] = {NULL, NULL};
	int x, i, z;
	size_t length = 1024;

	z = argc - argc;
	while (1)
	{
		printf("$ ");
		x = getline(command, &length, stdin);

		for (i = z; command[0][i] != '\0'; i++)
		{
			if (command[0][i] == 10)
				command[0][i] = '\0';
		}
		execArg(command, argv[0]);
	}
	return (x);
}
