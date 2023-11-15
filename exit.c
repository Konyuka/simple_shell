#include "main.h"

int is_num(char let);
int own_atoi(char *status);

/**
 * bltin_exit - Will exit shell
 * @argv: Shell exit status
 *
 * Return: Exits shell or returns EXIT_FAILURE
 */
int bltin_exit(char *const *argv)
{
	int aws;

	if (argv[1] == NULL)
	{
		freeing_memlst(&mem_head);
		freeing_static_memlst(&static_mem_head);
		exit(EXIT_SUCCESS);
	}
	else
	{
		aws = own_atoi(argv[1]);

		switch (aws)
		{
			case (-1):
				return (EXIT_FAILURE);
			default:
				freeing_memlst(&mem_head);
				freeing_static_memlst(&static_mem_head);
				exit(aws);
		}
	}
}

/**
 * is_num - If a char is a num
 * @let: Inputed char
 * Return: 1 Success, 0 Failure
 */
int is_num(char let)
{
	if (let >= '0' && let <= '9')
		return (1);

	return (0);
}

/**
 * own_atoi - Convert str to num
 * @status: Inpute Str
 * Return: Status as an int or -1
 */
int own_atoi(char *status)
{
	int aws = 0;
	int i = 0;

	if (status[i] == '-')
		return (-1);

	for (i = 0; status[i] != '\0'; i++)
	{
		if (is_num(status[i]))
		{
			aws = aws * 10 + status[i] - '0';
		}
		else
			return (-1);
	}
	if (aws > 2147483647)
	{
		return (-1);
	}
	else
		return (aws);
}


