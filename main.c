#include "main.h"
/**
 * main - prints a command
 * @argc: argument  counter
 * @argv: array of arguments
 * Return: number of characters read
 */
int main(int argc, char *argv[])
{
	store data;
	char inputstr[MAXCOM], *command[MAXLIST];
	int loop = 1;
	(void) argc;

	set_data(&data, argv[0]);
	while (loop == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		if (storeinput(inputstr) == 0)
		{
			if (!remove_comment(inputstr))
				continue;
			_strcpy(inputstr, remove_comment(inputstr));
			split_space(inputstr, command);
			if (inputstr[0] != '\0')
				cpathandexec(command, &data);
			else
				continue;
			data.counter += 1;
		}
		else
			break;
	}
	free_environ(&data);
	if (data._return < 0)
		return (255);
	return (data._return);
}
