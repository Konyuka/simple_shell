#include "main.h"

/**
  * exec_mngr - Control the CMD to right flow
  * @argv:- commandline arguements(CMD)
  * Return:- 0 Always
  */

int exec_mngr(char *const *argv)
{
	int right_value;

	right_value = exe_builtn(argv);

	if (right_value == 0)
		return (0);

	if (err_msg == 2)
	{
		right_value = (exe_extern(argv));
		if (right_value == 0)
			return (0);
	}

	return (-1);
}

/**
  * exe_builtn - The command to be executed
  * @argv:- Tables
  * Return:- Always 0
  */

int exe_builtn(char *const *argv)
{
	built_in fps[] = {
		{"exit", bltin_exit},
		{"env", bltin_env},
		{"cd", dir_change},
		{NULL, NULL}
	};

	int h;

	int (*built_in_fp)(char *const *argv);

	for (h = 0; fps[h].cmd; h++)
		if ((own_strcmp(argv[0], fps[h].cmd)) == 0)
		{
			built_in_fp = fps[h].fp;
			if ((built_in_fp(argv)) == 0)
			{
				return (0);
			}
		err_msg = 3;
		return (-1);
		}
	err_msg = 2;
	return (-1);
}

/**
  * exe_extern - Finds external CMD
  * @argv:- Table
  * Return:- 0 Always
  */

int exe_extern(char *const *argv)
{
	char **pat = NULL;
	int status, h;
	pid_t pid;

	if (checking_path(argv))
	{
		pat = (char **)alloc_mngr((char *)pat, (sizeof(char *) * 2));
		pat[0] = alloc_mngr(pat[0], (sizeof(char) * (own_strlen(argv[0]) + 1)));
		own_strncpy(pat[0], argv[0], own_strlen(argv[0]));
		pat[1] = NULL;
	}
	else
		pat = getting_pathh(argv);
	for (h = 0; pat[h]; h++)
	{
		if (access(pat[h], (R_OK | X_OK)) == 0)
		{
			switch ((pid = fork()))
			{
				case -1:
					return (-1);

				case 0:
					execve(pat[h], argv, environ);
					err_msg = 1;

					exit(EXIT_FAILURE);
				default:
					if ((waitpid(pid, &status, 0)) == -1)
						return (-1);
					else
						return (0);
			}
		}
	}
	err_msg = 2;
	return (-1);
}


