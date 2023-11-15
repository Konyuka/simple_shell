#include "main.h"

int buffer_check(char *buf);
void shfting_buffer(char *memory, ssize_t l);
ssize_t buff_copy(char **dst, char *source, ssize_t *start);

/**
  * get_line - the function that reads the CMDs
  * @buf:- the pointer to the CMD
  * Returns:- Always as 0
  */

ssize_t get_line(char **buf)
{
	static char lin[MAX_TTAL_ARGS];
	static ssize_t sum;
	ssize_t begin = 0;
	ssize_t copy = 0, cnt = 0;

	if ((buffer_check(lin)) == 0)
	{
		while ((cnt = read(STDIN_FILENO, lin, (MAX_TTAL_ARGS - 1))) > 0)
		{
			if (cnt == -1)
				return (-1);

			sum = sum + cnt;
			lin[cnt] = '\0';
			copy = buff_copy(&(*buf), lin, &begin);
			if (copy < cnt)
			{
				begin = 0;
				return (sum);
			}
		}
		sum = 0;
	}

	else
		copy = (buff_copy(&(*buf), lin, &begin) + 1);

	return (sum);
}

/**
 * buffer_check - the function to check the buffer
 * @buf: this tests the buffer
 * Return: the num of bytes needed
 */
int buffer_check(char *buf)
{
	int bytes = 0;

	while (buf[bytes])
		bytes++;

	return (bytes);
}



/**
  * shfting_buffer - this Shitfs the buffer
  * @l:- the bytes to be shifted
  * @memory:- this the memory
  * Returns:- Success as 0
  */

void shfting_buffer(char *memory, ssize_t l)
{
	ssize_t f = 0;

	while (memory[l] != '\0')
	{
		memory[f] = memory[l];
		f++;
		l++;
	}
	_settingmem(&memory[f], 0, (1024 - l));
}


/**
  * allocating_mem - the function that allocates the mem to buffer
  * @memory:- the memory allocted
  * Returns:- Always as 0
  */


int allocating_mem(char *memory)
{
	int xy = 0;

	while (memory[xy])
	{
		xy++;
	}

	return (xy);
}


/**
  * buff_copy - the copies to the buffer
  * @begin:- the results from a copy
  * @source:- Copy source
  * @dst:- Copy to
  * Returns:- Success as 0
  */

ssize_t buff_copy(char **dst, char *source, ssize_t *begin)
{
	ssize_t j;
	ssize_t cmt_copy = 0;

	for (j = 0; source[j] != '\n' && source[j] != '\0'; j++)
	{
		cmt_copy++;
	}

	if (source[j] == '\n')
	{
		*dst = alloc_mngr(*dst, (sizeof(char) * (cmt_copy + *begin + 1)));
		if (!(*dst))
			return (-1);
		own_strncpy((*dst + *begin), source, cmt_copy);
		shfting_buffer(source, (cmt_copy + 1));
		return (cmt_copy);
	}

	if (source[j] == '\0')
	{
		*dst = alloc_mngr(*dst, (sizeof(char) * (cmt_copy + *begin + 1)));
		if (!(*dst))
			return (-1);
		own_strncpy((*dst + *begin), source, (cmt_copy));
		*begin = *begin + cmt_copy;
		return (cmt_copy);
	}

	return (cmt_copy);
}