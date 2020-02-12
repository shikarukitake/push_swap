//
// Created by positivedespair on 2/11/20.
//

#ifndef CHECKER_H
#define CHECKER_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# define FALSE 0
# define TRUE 1
# define AND &&
# define OR ||

typedef struct  s_stack
{
    struct s_stack *previous;
    int     value;
    int     len;
}               t_stack;

typedef struct s_dynamicArr
{
    int     *array;
    int     len;
    int     freeSpace;
}              t_dynamicArr;

/*
 *  STACK
 */

void        pushStack(t_stack **stack, int value);
int         popStack(t_stack **stack);
void        swap(t_stack **stack);
void        rotate(t_stack **stack);
void        reverseRotate(t_stack **stack);
void        printTwoStacks(t_stack *stackA, t_stack *stackB);
void        printStack(t_stack *stack);
t_stack     *init_stack(t_stack *previous, int value);

/*
 * Dynamic Array
 */

void        initDArr(t_dynamicArr **arr);
void        cpyIntArray(int *dest, int *src, int freeOrNot, int len);
void        addDArr(t_dynamicArr **arr, int value);
void        printDArr(t_dynamicArr *arr);

#endif //CHECKER_H
