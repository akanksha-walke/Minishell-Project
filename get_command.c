#include "main.h"

//Function to get the command entered by user in stdin
int parse_function(char ***argv, char *buff, int *idx_arr, int *argc)
{
	int index = 0, j_index = 0, k_index = 0, count = 0;
	char *str = buff;

	// Calculate the length of the command
	int length =  strlen(buff);

	// Initializing the array for index
	idx_arr[k_index++] = 0;

	while (index <= length)
	{
		// Allocate memory for first command
		if (j_index == 0)
			*argv = malloc(1* sizeof(char *));

		// Reallocate memory for the remaining commands
		else
			*argv = realloc(*argv, (j_index + 1)*sizeof(char *));

		// Check for spaces and null character
		if (buff[index] == ' ' || buff[index] == '\0')
		{
			// Replace with NULL
			buff[index] = '\0';

			// If pipe is found
			if (strcmp(str, "|") == 0)
			{
				// Store the next position's index in an array
				idx_arr[k_index++] = j_index + 1;

				// Count the number of pipes
				count++;

				// Replace the pipe with NULL
				*(*argv + j_index) = NULL;
			}
			else
			{
				// Allocate memory for the store the string
				*(*argv + j_index) = malloc(strlen(str) + 1);

				// Store the string
				strcpy(*(*argv + j_index), str);
			}
			// Increment the argv index
			j_index++;

			// Store the next command
			str = buff + index + 1;
		}
		// increment the buff index
		index++;
	}
	// Store the argument count
	*argc = j_index;

	// Reallocate memory for the last command
	*argv = realloc(*argv, (j_index + 1)*sizeof(char *));

	// Terminate with NULL
	*(*argv + j_index) = NULL;
	
    // Return the count of pipes
	return count;
}
