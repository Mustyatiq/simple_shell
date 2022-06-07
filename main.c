#include "main.h"
/**
 * main - prints a command
 * @argc: argument  counter
 * @argv: array of arguments
 * Return: number of characters read
 */
int main(int argc, char *argv[])
{
	char inputstr[MAXCOM], *command[MAXLIST];
	int z, loop = 1;

	z = argc - argc;
	while (loop == 1)
	{
		printf("$ ");
		if (storeinput(inputstr) == 0)
		{
			split_space(inputstr, command);
			execArg(command, argv[0]);
		}
		else
			break;
	}
	return (z);
}
