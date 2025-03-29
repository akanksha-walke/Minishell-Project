#include "main.h"

// Execution of built-in-commands that involves system calls
int system_call(char *buff)
{
	char *str;
	// If the command is "pwd"
	if (strcmp(buff, "pwd") == 0)
	{
		// Invoke getchwd system call to print the cuurent working directory
		getcwd(buff, 100);
		printf("%s\n", buff);
	}
	// System call for make new directory
	else if (strcmp(buff, "mkdir") == 0)
	{
		mkdir(buff + 6, 0777);
		buff[0] = '\0';
	}

	// Sytem call to change directory
	else if (strcmp(buff, "cd") == 0)
	{
		if ((buff[3]) == '\0' || strlen(buff + 3) == 0)
		{
			str =  "/home/emertxe/";
			printf("%s\n", str);
			chdir(str);
		}
		else
		{
			chdir(buff + 3);
			buff[3] = '\0';
		}
	}
	// System call to remove directory
	else if (strcmp(buff, "rmdir") == 0)
	{
		rmdir(buff + 6);
		buff[3] = '\0';
	}
	else
		return 0;

	return 1;
}

// Function to execute special commands like echo
int check_echo(char **argv)
{
	int index = 0;

	if (strcmp(argv[0], "echo") == 0)
	{
		// To print the exit status
		if (strcmp(argv[1], "$?") == 0)
			printf("%d\n", WEXITSTATUS(status));

		// To print the process id
		else if (strcmp(argv[1], "$$") == 0)
			printf("%d\n", getpid());

		// To print executable path
		else if (strcmp(argv[1], "$SHELL") == 0)
		{
			printf("%s\n", string);
		}

		else
			return 0;
		return 1;
	}
	return 0;
}
