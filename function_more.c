
#include "main.h"

/**
  * own_strncpy - this copies a strg
  * @destination:- thi is the destination
  * @source:- the string
  * @count:- the bytes to be copied
  * Returns:- Success as 0
  */

char *own_strncpy(char *destination, const char *source, size_t count)
{
	size_t h = 0;

	while (h < count)
	{
		if (source[h] == '\0')
		{
			break;
		}
		destination[h] = source[h];
		h++;
	}

	destination[h] = '\0';

	while (h < count)
	{
		destination[h] = '\0';
		h++;
	}

	return (destination);
}


/**
  * own_strlen - this gets & returns the str length
  * @string:- the string
  * Returns:- Always as 0
  */


size_t own_strlen(char *string)
{
	size_t str_len = 0;

	if (string)
		while (string[str_len] != '\0')
			str_len++;

	return (str_len);
}



/**
  * own_strcmp - this compares the tw0 string
  * @string1:- str 1
  * @string2:- str 2
  * Return:- Always 0
  */

int own_strcmp(char *string1, char *string2)
{
	int h = 0;


	while (string1[h] != '\0')
	{
		if (string1[h] < string2[h])
		{
			return (string1[h] - string2[h]);
		}

		if (string1[h] > string2[h])
		{
			return (string1[h] - string2[h]);
		}
		h++;
	}

	if (string2[h] != '\0')
	{
		return (string1[h] - string2[h]);
	}

	return (0);
}


/**
  * own_strncmp - A function to compare two strings
  * @string1:- String one
  * @string2: String two.
  * @num:- Num of Chars to compare
  * Return:- Always 0
  */

int own_strncmp(char *string1, char *string2, size_t num)
{
	size_t m = 0;

	while (m < num && string1[m] != '\0')
	{
		if (string1[m] < string2[m])
		{
			return (string1[m] - string2[m]);
		}

		if (string1[m] > string2[m])
		{
			return (string1[m] - string2[m]);
		}

	m++;
	}
	if (m < num && string2[m] != '\0')
	{
		return (string1[m] - string2[m]);
	}
	return (0);
}



/**
  * own_strcat - the joins strings
  * @destination:- the joined string
  * @source: the first string
  * Returns:- Always as 0
  */

char *own_strcat(char *destination, char *source)
{
	int source_index = 0;
	int destination_index = 0;


	for (; destination[destination_index] != '\0';)
	{
		destination_index++;
	}

	for (; source[source_index] != '\0';)
	{
		destination[destination_index] = source[source_index];
		source_index++;
		destination_index++;
	}


	destination[destination_index] = '\0';
	return (destination);
}