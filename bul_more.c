#include "main.h"

/**
  * counting_digt - count digits
  * @number:- Counted number
  * Return:- 0 Always
  */

size_t counting_digt(size_t number)
{
	size_t digitcount = 0;

	while (number != 0)
	{
		number /= 10;
		digitcount++;
	}

	return (digitcount);
}

/**
  * own_itoa - chang num to string
  * @ba:- The string base
  * @buff:- an array of string
  * @num:- The inpu
  * Return:- O Always
  */

char *own_itoa(size_t num, char *buff, int ba)
{
	int signn = 1;
	int idy = 0;
	size_t remember = 0;

	if (num == 0)
	{
		buff[idy++] = '0';
		buff[idy] = '\0';
	}
	while (num)
	{
		remember = num % ba;
		buff[idy++] = '0' + remember;
		num /= ba;
	}
	if (signn < 0)
	{
		buff[idy++] = '-';
	}
	if (num)
		buff[idy] = '\0';
	return (reverse_string(buff));
}


