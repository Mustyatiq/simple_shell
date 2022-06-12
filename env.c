#include "main.h"
/**
 * copy_info - copies value of var int var
 * @name: variable name
 * @value: variable value
 * Return: new env
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * len);
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}
/**
 * set_env - sets or modifies an environment variable
 * @name: variable name
 * @value: variable value
 */
void set_env(char *name, char *value)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; _environ[i]; i++)
	{
		var_env = _strdup(_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(_environ[i]);
			_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}
	_environ = _reallocdp(_environ, i, sizeof(char *) * (i + 2));
	_environ[i] = copy_info(name, value);
	_environ[i + 1] = NULL;
}
/**
 * _csetenv - checks if setenv is correctly called
 * command - command passed
 * Return: 1 on success
 */
int _csetenv(char **command)
{
	if (command[1] == NULL || command == NULL)
		write(STDERR_FILENO, "Failed\n", 7);
	else
		set_env(command[1], command[2]);
	return (1);
}
