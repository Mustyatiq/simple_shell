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
		write(STDIN_FILENO, "$ ", 2);
		if (storeinput(inputstr) == 0)
		{
			split_space(inputstr, command);
			if (inputstr[0] != '\0')
				execArg(command, argv[0]);
			else
				continue;
		}
		else
			break;
	}
	return (z);
}
