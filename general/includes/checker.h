//
// Created by positivedespair on 2/11/20.
//

#ifndef CHECKER_H
#define CHECKER_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"


typedef struct  s_stack
{
    struct s_stack *previous;
    int     value;
    int     len;
}               t_stack;

typedef struct  s_dynamicArr
{
    int     *array;
    int     len;
    int     freeSpace;
}               t_dynamicArr;

/*
 *  Struct for doing command ra or rra
 */

typedef struct  s_command
{
    int     count;
    char    *command;
    char    *commandRev;
}               t_command;

/*
 *  STACK
 */

void            pushStack(t_stack **stack, int value);
int             popStack(t_stack **stack);
void            swap(t_stack **stack);
void            rotate(t_stack **stack);
void            reverseRotate(t_stack **stack);
void            printTwoStacks(t_stack *stackA, t_stack *stackB);
void            printStack(t_stack *stack);
t_stack         *init_stack(t_stack *previous, int value);
void            freeStack(t_stack *stack);

/*
 * Dynamic Array
 */

void            initDArr(t_dynamicArr **arr);
void            cpyIntArray(int *dest, int *src, int freeOrNot, int len);
void            addDArr(t_dynamicArr **arr, int value);
void            printDArr(t_dynamicArr *arr);
t_dynamicArr    *initDArrFromInt(int *array, int len);

/*
 * Service
 */

void            ft_error(void);
void            ft_errorText(char const *text);
int             stackIsSorted(t_stack *stackA);
void            checkSorted(t_stack *stackA, t_stack *stackB);
int             isOnlyDigits(char *s);
char            **ft_strsplit(char const *s, char c);
size_t          ft_w_count(char const *s, char c);
int             *fillArrayFromStack(t_stack *stack, int sortOrNot);

/*
 * Reading
 */

int             checkCommand(char *command);
void            readingFromSTDIN(t_dynamicArr    **dArr);
int             checkDublicates(t_stack *stack);

/*
 * Push Swap commands
 */

void            ft_sa(t_stack **stackA, t_stack **stackB, int flag);
void            ft_sb(t_stack **stackA, t_stack **stackB, int flag);
void            ft_ss(t_stack **stackA, t_stack **stackB, int flag);
void            ft_pa(t_stack **stackA, t_stack **stackB, int flag);
void            ft_pb(t_stack **stackA, t_stack **stackB, int flag);
void            ft_ra(t_stack **stackA, t_stack **stackB, int flag);
void            ft_rb(t_stack **stackA, t_stack **stackB, int flag);
void            ft_rr(t_stack **stackA, t_stack **stackB, int flag);
void            ft_rra(t_stack **stackA, t_stack **stackB, int flag);
void            ft_rrb(t_stack **stackA, t_stack **stackB, int flag);
void            ft_rrr(t_stack **stackA, t_stack **stackB, int flag);
void            initFTable(void **func_table);
void            execCommands(t_dynamicArr *dArr, t_stack **stackA, t_stack **stackB, int flag);

#endif //CHECKER_H
