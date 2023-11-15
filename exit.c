#include "main.h"

int is_num(char let);
int own_atoi(char *status);

/**
 * bltin_exit - this will exit the shell
 * @argv: the shell exit status
 *
 * Return: this exits the shell or returns FAILURE
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
 * is_num - If is a char is a number
 * @let: the inputed char
 * Returns: 1 as Success and 0 as Failure
 */
int is_num(char let)
{
	if (let >= '0' && let <= '9')
		return (1);

	return (0);
}

/**
 * own_atoi - the onverted string to num
 * @status: Inpute String
 * Returns: Status as an int or -1
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