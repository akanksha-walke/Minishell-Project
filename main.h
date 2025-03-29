/*-------------------------------------------------
Name        :Akanksha Walke
Date        :05/12/2021
Description :Implement a minimalistic shell, 
             mini-shell(msh) as part of the Linux Internal module.
Output      :[MINISHELL]$ ls
             a.out  built_in_command.c  get_command.c  main.c  main.h  Makefile  out.txt  promt.c
------------------------------------------------*/

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio_ext.h>
#include <signal.h>
#include <signal.h>
#define BUFFER_SIZE 256
#include <errno.h>
#include <getopt.h>

typedef struct _node
{
	char process_name[20];
	char priority;
	char state[20];
	pid_t pid;
	int process_num;
	struct _node *next, *prev;
}jobs;

int status;
pid_t pid;
int ch_flag, z_flag, ctr_flag;
char buff[100], string[100];;


//Function Declaration

// Parse function to read the commands
int parse_function(char ***argv, char *buff, int *idx_arr, int *argc);

// Execution of commands that involves system calls
int system_call(char *buff);

// Function to create new prompt
int new_prompt(char *buff, char *new_shell);

// Function to return back to the prompt
int return_prompt(char *buff);

// Function to execute special commands
int check_echo(char **argv);

// Maintain priority for background/Stopped processes
void check_priority(void);

// Inserting a job
void insert_job(char *str);

// Delete the jobs from the list
void del_job(pid_t pid);

// Print the job
void print_jobs(void);

// Signal handler for the child process
void child_sig_handler(int signum, siginfo_t *siginfo, void *context);

// Signal handler for ctrl + c
void ctrl_c_handler(int signum);

// Signal handler for ctrl + z
void ctrl_z_handler(int signum);

// Function call for foreground and background process
int fg_bg(void);

#endif
