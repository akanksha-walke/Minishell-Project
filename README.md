
   # **Mini-Shell**

  ![p4_1](https://github.com/user-attachments/assets/9d886311-fb91-4f0d-99a5-d02c8af0d74f)

## **Brief Description**

A simple implementation of the Unix Shell in the C Programming language. This project was coded and tested in Ubuntu 17.04.

**How to run**

To test this project, download all the files and folders into a directory.
Compile and run minishell

**Implementation Description**

Minishell has both built-in and external commands. The built-in commands are implemented in build_in_command.c. The main.h file contains the header and main.c contains the function calls.

When you type a command into minishell, it first looks for the command in the list of built-ins that it maintains.

If present, it will call the corresponding function (the mapping from built-in command name to the command function is implemented using function pointers for better performance and to eliminate the need for cumbersome switch case statements).
If not, it will fork a new process, load the command's image into the child process and wait for the child process to finish execution before displaying the prompt again.
If the command is not found (the corresponding .c file is not found), an error message indicating that the command was not found will be displayed.
When errors occur, appropriate error messages will be displayed.

**Commands**

Only a very small number of commands have been implemented. The commands are:

**System Calls**

• cd
• mkdir
• rmdir
• sleep
• exit
• pwd

 **IPC**
 
• N-pipe’s

 **Process**
 
• ls
• date
• Any executable file

 **Echo family**
 
• echo $$
• echo $?
• echo $SHELL
• PS1

 **Signals**
 
• SIGINT
• SIGTSTP
• fg
• bg
• jobs

**Output**

:[MINISHELL]$ ls

             a.out    built_in_command.c    get_command.c    main.c    main.h    Makefile    out.txt    promt.c
