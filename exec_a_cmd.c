#include "simple_shell.h"

/**
 * execute_cmd - Fuction that execute user cmds
 * @command_args: formal parameter
 *
 * Return: 1
 */
int execute_cmd(char *command_args[])
{
	pid_t process_id;
	int pid_status;

	process_id = fork();
	if (process_id == 0) /* Child Process Running */
	{
		char *envp[] = {NULL}; /* Set a dummy envp 4 now */

		if (execve(command_args[0], command_args, envp) == -1)
		{
			perror(":( Execve Failed");
		}
		exit(EXIT_FAILURE);
	}
	else if (process_id < 0)
	{
		perror(":( Fork Failed");
	}
	else
	{
		/* Parent Process Is Running */
		wait(&pid_status); /* Wait 4 child_pid to complete */
		if (WIFEXITED(pid_status) || WIFSIGNALED(pid_status))
		{
			return (0); /* Return 0 for successful execution */
		}
		else
		{
			perror(":( Child_process error");
			return (-1); /* Return -1 to indicate an error */
		}
	}
	return (1); /* continue to execution */
}

