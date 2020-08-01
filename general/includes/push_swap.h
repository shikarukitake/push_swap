//
// Created by positivedespair on 7/19/20.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "checker.h"

void            change_chr(char *string, char f, char c);
char            *get_str_commands3(int *minMeanMax, int *swap);
t_dynamicArr    *get_darr_commands(char *commandz);
char            *sort_three(t_sts *sts, int flag);
char            *get_string(t_stack *stack_swap);
void            *sort_two(t_sts *sts);
int             exist_in_stack(t_stack *stack, int value);
int             find_next_stacka(t_sts *sts, int value);
int             find_next_stackb(t_sts *sts, int value);
t_command       *ra_or_rra(t_sts *sts, int value);
t_command       *rb_or_rrb(t_sts *sts, int value);
char            *commands_from_tcomm(t_command *comm, char const *paOrPb);
void            do_r_or_rr(t_sts *sts, int value, char *paOrPb);
int             smaller_or_greater(t_stack *stack, int value);
void            sort_end(t_sts *sts);
int             find_id_max_in_stack(t_stack *stack);
void            sort_end_stackb(t_sts *sts);
char            *sort_five(t_sts *sts);
t_chunks        *init_chunks(int len);
void            create_chunks_arr(t_chunks *chunks, int howManyChunks);
t_chunks        *fill_chunks(t_stack *stack, int howManyChunks);
int             exists_in_chunk(t_stack *stack, t_chunks *chunks, int current_c);
void            init_chunks_comm(t_sts *sts, int how_many_chunks);
int             binary_search(int *array, int len, int value);
int             value_in_chunk(t_chunks *chunks, int value);
void            find_holds(t_sts *sts);
void            find_comm(t_sts *sts, int len_of_stack);
void            push_to_stackb(t_sts *sts);
char            *sort_all(int how_many_chunks, t_sts *sts);
void            sort_stack(t_sts *sts);
int             *arr_from_stack(t_stack *stack, int sortOrNot);
int             check_dublicates(t_stack *stack);

#endif //PUSH_SWAP_H
