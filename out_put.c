#include "main.h"

/**
 * bltin_env - this prints the procee env
 * @argv: this is the command table
 *
 * Returna: 0 as Success and -1 as Failure
 */
int bltin_env(char *const *argv)
{
    size_t length, row;

    if (!argv[1])
    {
        for (row = 0; environ[row]; row++)
        {
            length = own_strlen(environ[row]);

            if ((write(STDOUT_FILENO, environ[row], length)) == -1)
                return (-1);
            if ((write(STDOUT_FILENO, "\n", 1)) == -1)
                return (-1);
        }
    }
    else
    {
        errno = ENOENT;
        return (-1);
    }
    return (0);
}