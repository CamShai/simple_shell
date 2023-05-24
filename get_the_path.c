#include "simple_shell.h"
#include<unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
/**
 *get_path -this  locates the full path of a command in the directories
 *           in listed in the PATH environment variable.
 *@cmd: name command  to be located.
 *
 * Return : return a pointer on succss to the full path of the command
 *         if found, or  pointer to th command itself if it exists in the
 *         current working directory. Return NULL if  command is not found in directories.
 */
char *get_path(char *cmd)
{
	char *path, *copy_of_the_path, *the_path_token, *path_file;
	int cmd_length, dir_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		copy_of_the_path = strdup(path);
		cmd_length = strlen(cmd);
		the_path_token = strtok(copy_of_the_path, ":");

		while (the_path_token != NULL)
		{
			dir_length = strlen(the_path_token);
			path_file = malloc(cmd_length + dir_length + 2);
			strcpy(path_file, the_path_token);
			strcat(path_file, "/");
			strcat(path_file, cmd);
			strcat(path_file, "\0");
			if (stat(path_file, &buffer) == 0)
			{
				free(copy_of_the_path);
	
				return (path_file);
			}
			else
			{
			free(path_file);
			the_path_token = strtok(NULL, ":");
			}
		}
		free(copy_of_the_path);

		if (stat(cmd, &buffer) == 0)
		{
		return (cmd);
		}
		return (NULL);

	}
	return (NULL);
}
