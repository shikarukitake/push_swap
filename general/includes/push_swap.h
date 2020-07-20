//
// Created by positivedespair on 7/19/20.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "checker.h"

/*
 * There is sorted array with chunk number
 */
typedef struct  s_chunks
{
    int     len;
    int     *array;
    int    *chunk;
    int     current_c;

}               t_chunks;

typedef struct  s_sts
{
    t_command   *comm;
    t_chunks    *chunks;
    t_stack     **stackA;
    t_stack     **stackB;
    size_t      firstHoldI;
    size_t      secondHoldI;
    char        *commands;
}               t_sts;


#endif PUSH_SWAP_H
