#include "main.h"
/**
 * main - prints a command
 * Return: number of characters read
 */
int main(void)
{
	char *command[2] = {NULL, NULL};
	int x, i;
	size_t length = 32;

	printf("$ ");
	x = getline(command, &length, stdin);

	for (i = 0; command[0][i] != '\0'; i++)
	{
		if (command[0][i] == 10)
			command[0][i] = '\0';
	}
	printf("%s does this: \n", command[0]);
	execve(command[0], command, NULL);
	return (x);
}
