
#include "main.h"

/**
 * _setting mem - This is to set the memory
 * @k:- The # of bytes
 * @c:-  bytes constant
 * @j:- the printing location
 * Returns:- Success as 0
 */

char *_settingmem(char *j, char c, unsigned int k)
{
    unsigned int x = 0;

    while (x < k)
    {
        j[x] = c;
        x++;
    }

    return (j);
}

/**
 * own_realloc - This Allocates the memory
 * @sizenw:- New memory size
 * @pointer:- the previuos allocations
 * Returns:- Success as 0
 */

char *own_realloc(char *pointer, size_t sizenw)
{
    size_t j = 0;
    size_t sizeod = own_strlen(pointer);
    char *repointed;

    if (sizenw == sizeod)
        return (pointer);

    if (sizenw == 0 && pointer != NULL)
    {
        free(pointer);
        return (NULL);
    }

    repointed = malloc(sizenw);
    if (!repointed)
    {
        return (pointer);
    }

    if (pointer)
    {
        for (j = 0; j < sizeod && j < sizenw; j++)
        {
            *(repointed + j) = *(pointer + j);
        }
    }
    _settingmem((repointed + sizeod), 0, (sizenw - sizeod));

    return (repointed);
}

/**
 * freeing the memorylst - Frees mem
 * @head:- and Prints to strct
 */

void freeing_memlst(mem_list **head)
{
    mem_list *pmt;

    if (head)
    {
        while (*head)
        {
            pmt = *head;
            *head = (*head)->next;

            if (pmt->mem_ptr)
            {
                free(pmt->mem_ptr);
            }
            free(pmt);
        }

        *head = NULL;
    }
}

/**
 * add_memnode - this to Link the node
 * @pointer:- Pointer to the created node
 * @head:- Pointer to the other node
 * Return:- Success 0
 */

mem_list *add_memnode(mem_list **head, char *pointer)
{
    mem_list *nw;

    nw = malloc(sizeof(mem_list));

    if (!nw)
        return (NULL);

    nw->mem_ptr = pointer;
    nw->next = *head;

    *head = nw;

    return (*head);
}

/**
 * alloc_mngr - this allocates the space for memory
 * @pointer:- this Pointing to new mem
 * @siz:- the required size
 * Returns:- Always as 0
 */

char *alloc_mngr(char *pointer, size_t siz)
{
    pointer = own_realloc(pointer, siz);

    if (!(pointer))
    {
        perror("hsh");
        freeing_memlst(&mem_head);
        return (NULL);
    }

    mem_head = add_memnode(&mem_head, pointer);

    return (pointer);
}