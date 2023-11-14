#include "main.h"

void reciev_signal(int sinal);

/**
 * reciev_signal - this is to write a prompt
 * @sinal:- the Ne attribs
 */

void reciev_signal(int sinal __attribute__((unused)))
{
    write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - this is the main entry point
 * @argv:- the args vector
 * @argc:- the number of args
 * Returns:- Always as 0
 */

int main(int argc __attribute__((unused)), char **argv)
{
    char **token = NULL;
    char *lik = NULL;
    size_t count_lp = 1;

    do
    {
        token = NULL;
        lik = NULL;

        if (isatty(STDIN_FILENO))
        {
            write(STDOUT_FILENO, "$ ", 2);
        }
        signal(SIGINT, reciev_signal);

        if ((get_line(&lik)) == 0)
        {
            freeing_memlst(&mem_head);
            freeing_static_memlst(&static_mem_head);

            if (isatty(STDIN_FILENO))
            {
                write(STDOUT_FILENO, "\n", 1);
            }
            exit(EXIT_SUCCESS);
        }
        if (lik)
            token = own_strtok(lik);
        if (token)
            if ((exec_mngr(token)) == -1)
                printing_error(count_lp, argv[0], token);

        freeing_memlst(&mem_head);
        count_lp++;

    } while (1);

    freeing_static_memlst(&static_mem_head);
    return (0);
}