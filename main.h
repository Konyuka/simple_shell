
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <stdarg.h>
#include <limits.h>

#define MAX_TTAL_ARGS 1024

/**
 * the struct that allocation_history - tracks and stores allocations
 * @mem_ptr: pointer to allocated memory
 * @next: pointer to next node in list
 *
 * Description: stores a pointer to each allocation, allowing
 * greater organization and more efficient freeing
 */
typedef struct allocation_history
{
    char *mem_ptr;
    struct allocation_history *next;

} mem_list;

/**
 * struct built_ins - this Has builtin to handle
 * @cmd: the Pointer to char
 * @fp: the function to execute
 */
typedef struct built_ins
{
    char *cmd;
    int (*fp)(char *const *);
} built_in;

/****Global vars***/
extern char **environ;
extern mem_list *mem_head;
mem_list *mem_head;
extern mem_list *static_mem_head;
mem_list *static_mem_head;
extern size_t err_msg;
size_t err_msg;

/***** FUNCTIONS FOUND IN buildin.c *****/
int cd_Home(void);
int dir_change(char *const *argv);
int cd_cur(void);
int cd_prev(void);
int parent_cd(void);

/***** FUNCTIONS FOUND IN  exit.c *****/
/*int is_num(char let);*/
/*int own_atoi(char *status);*/
int bltin_exit(char *const *argv);

/***** FUNCTIONS FOUND IN  getline.c *****/
ssize_t get_line(char **buf);
/*void shfting_buffer(char *memory, ssize_t l);*/
int allocating_mem(char *memory);
/*ssize_t buff_copy(char **dst, char *source, ssize_t *start);*/
char *alloc_mngr(char *pointer, size_t siz);
int buffer_check(char *buf);

/***** FUNCTIONS FOUND IN  own_strtoken.c *****/
/*size_t cnt_tokens(char *buffer);*/
/*size_t tok_length(char *buf, size_t tokneed);*/
char **own_strtok(char *buffer);

/***** FUNCTIONS FOUND IN  path_finder.c ****/
char **getting_pathh(char *const *argv);
size_t checking_path(char *const *argv);
size_t counting_path(char *pat);
size_t length_path(char *pat_pointer);

/***** FUNCTIONS FOUND IN  bul_more.c *****/
size_t counting_digt(size_t number);
char *own_itoa(size_t num, char *buff, int ba);

/***** FUNCTIONS FOUND IN  pet_fun.c *****/
char *tar_get(char *var_name);
int cd_user(char *argv);
int set_PWD(char *val);
int set_OLDPWD(void);
int cd_arg(char *argv);

/***** FUNCTIONS FOUND IN  shell.c *****/
void reciev_signal(int sinal __attribute__((unused)));

/***** FUNCTIONS FOUND IN  exe.c *****/
int exec_mngr(char *const *argv);
int exe_builtn(char *const *argv);
int exe_extern(char *const *argv);

/***** FUNCTIONS FOUND IN  memery_strct.c *****/
char *_settingmem(char *j, char c, unsigned int k);
char *own_realloc(char *pointer, size_t sizenw);
void freeing_memlst(mem_list **head);
mem_list *add_memnode(mem_list **head, char *pointer);
char *alloc_mngr(char *pointer, size_t siz);

/***** FUNCTIONS FOUND IN  out_put.c *****/
int bltin_env(char *const *argv);
void printing_error(size_t loop_cnt, char *argv, char **tok_arry);
/*char *three_case(char *errcus, char **tok_ary);*/

/***** FUNCTIONS FOUND IN  parser.c *****/
char *reverse_string(char *str);
void freeing_static_memlst(mem_list **head);
void freeing_memlst(mem_list **head);

/***** FUNCTIONS FOUND IN  function_more.c *****/
char *own_strncpy(char *destination, const char *source, size_t count);
size_t own_strlen(char *string);
int own_strcmp(char *string1, char *string2);
int own_strncmp(char *string1, char *string2, size_t num);
char *own_strcat(char *destination, char *source);

#endif