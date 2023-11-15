#include "main.h"

char *three_case(char *errcus, char **token_array);

/**
 * printing_error -the  error to print
 * @argv: this carries the shells name
 * @tok_arry: This is the needed token for error the message
 * @loop_cnt: loop iteration
 */
void printing_error(size_t loop_cnt, char *argv, char **tok_arry)
{
	char *tagged_err = NULL, *loop_num = NULL, *err_cus = NULL;
	size_t err_cus_len, tagged_err_len;
	size_t digit_amount = counting_digt(loop_cnt);
	size_t token1_len = own_strlen(tok_arry[0]);
	size_t token2_len = own_strlen(tok_arry[1]);
	size_t argv_len = own_strlen(argv);
	size_t total_alloc = argv_len + digit_amount + token1_len + token2_len + 6;

	switch (err_msg)
	{
		case (2):
			err_cus = alloc_mngr(err_cus, (sizeof(char) * 12));
			err_cus = ": not found\0";
			break;
		case (3):
			err_cus = three_case(err_cus, tok_arry);
			if (err_cus == NULL)
				return;
			break;
		default:
			perror(argv);
			return;
	}

	loop_num = alloc_mngr(loop_num, (sizeof(char) * (digit_amount + 1)));
	own_itoa(loop_cnt, loop_num, 10);

	err_cus_len = own_strlen(err_cus);
	total_alloc += err_cus_len;

	tagged_err = alloc_mngr(tagged_err, sizeof(char) * total_alloc);

	own_strncpy(tagged_err, argv, argv_len);
	own_strcat(tagged_err, ": ");
	own_strcat(tagged_err, loop_num);
	own_strcat(tagged_err, ": ");
	own_strcat(tagged_err, tok_arry[0]);
	own_strcat(tagged_err, err_cus);
	if (err_msg == 3)
		own_strcat(tagged_err, tok_arry[1]);
	own_strcat(tagged_err, "\n");

	tagged_err_len = own_strlen(tagged_err);

	write(STDERR_FILENO, tagged_err, tagged_err_len);
}

/**
 * three_case - this is the message
 * @errcus: the error message saved here
 * @token_array: The token for error message
 * Return: NULL or Pounter to error message
 */
char *three_case(char *errcus, char **token_array)
{
	size_t token1_len = own_strlen(token_array[0]);
	size_t token2_len = own_strlen(token_array[1]);

	if (token1_len == 4)
	{
		errcus = alloc_mngr(errcus, (sizeof(char) * 19));
		errcus = ": Illegal number: \0";
		return (errcus);
	}
	else if (token1_len == 2)
	{
		errcus = alloc_mngr(errcus, (sizeof(char) * 15));
		errcus = ": can't cd to \0";
		return (errcus);
	}

	errcus = alloc_mngr(errcus, sizeof(char) * token1_len + token2_len + 5);
	own_strncpy(errcus, token_array[0], token1_len);
	own_strcat(errcus, ": '");
	own_strcat(errcus, token_array[1]);
	own_strcat(errcus, "'");

	errno = ENOENT;
	perror(errcus);
	return (NULL);
}