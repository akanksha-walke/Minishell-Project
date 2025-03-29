#include "main.h"

// Function to create new prompt
int new_prompt(char *buff, char *new_shell)
{
	if (strncmp(buff, "PS1=", 4) == 0)
	{
		if (buff[4] != ' ' && buff[4] != '\t' )
			strcpy(new_shell, buff + 4);
		else
			printf("PS1: command not found\n");
		return 1;
	}
	return 0;
}

// Function to return back to the prompt
int return_prompt(char *buff)
{
	if (ctr_flag || strlen(buff) == 0)
	{
		if (ctr_flag)
		{
			printf("\n");
			ctr_flag = 0;
		}
		return 1;
	}
	else
		return 0;

}
