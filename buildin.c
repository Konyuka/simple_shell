#include "main.h"

/**
  * cd_Home - this is to change dir to home
  * Return:- 0 as Always
  */
int cd_Home(void)
{
	char *dir_target = NULL;

	dir_target = tar_get("HOME=");

	if (dir_target)
	{
		if (chdir(dir_target) == 0)
		{
			set_OLDPWD();
			set_PWD(dir_target);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}


/**
  * dir_change - this is to shift dir
  * @argv:- the executed command
  * Returns:- 0 as Always
  */
int dir_change(char *const *argv)
{
	if (argv[1] == NULL || !(own_strcmp(argv[1], "~")))
	{
		if (cd_Home())
			return (-1);
	}
	else if (!(own_strcmp(argv[1], ".")))
	{
		if (cd_cur())
			return (-1);
	}
	else if (!(own_strcmp(argv[1], "..")))
	{
		if (parent_cd())
			return (-1);
	}
	else if (!(own_strcmp(argv[1], "-")))
	{
		if (cd_prev())
			return (-1);
	}
	else if ((!(own_strncmp(argv[1], "~", 1)) && (argv[1][1] != '\0')))
	{
		if (cd_user(argv[1]))
			return (-1);
	}
	else
	{
		if (cd_arg(argv[1]))
			return (-1);
	}
	return (0);
}
/**
 * cd_cur - this is to switch directory to home
 * Return: 0 as Success, -1 as Failure
 */

int cd_cur(void)
{
	char *dir_target = NULL;

	dir_target = tar_get("PWD=");

	if (dir_target)
	{
		int chdir_result = chdir(dir_target);

		if (chdir_result == 0)
		{
			set_OLDPWD();
			set_PWD(dir_target);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);
}
/**
  * cd_prev - this is to switch to the prev dir
 * Return: 0 as the Success and -1 as Failure
 */
int cd_prev(void)
{
	char *tag_directory = NULL;

	tag_directory = tar_get("OLDPWD=");
	if (tag_directory)
	{
		if (chdir(tag_directory) == 0)
		{
			set_OLDPWD();
			set_PWD(tag_directory);
			write(STDOUT_FILENO, tag_directory, own_strlen(tag_directory));
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		else
			return (-1);
	}
	return (-1);

}

/**
 * parent_cd - the changes to the parent directory
 * Returns: 0 on Success and 1 as Failure
 */
int parent_cd(void)
{
	char *dir_target = NULL;
	size_t i;

	dir_target = tar_get("PWD=");
	if (dir_target)
	{
		for (i = own_strlen(dir_target); dir_target[i] != '/';)
			i--;

		for (; dir_target[i]; i++)
			dir_target[i] = '\0';

		if (chdir(dir_target) == 0)
		{
			set_OLDPWD();
			set_PWD(dir_target);
			return (0);
		}
	}
	return (-1);
}