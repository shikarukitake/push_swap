//
// Created by positivedespair on 7/25/20.
//

#ifndef MACRO_H
# define MACRO_H

# define BUFF_SIZE 42
/*
** Exit Checks
*/
# define ERROR_CHECK(x) if (x) return (-1)
# define ZERO_CHECK(x) if (x) return (0)
# define NULL_CHECK(x) if (x) return (NULL)
# define BREAK_CHECK(x) if (x) break
/*
** Status Checks
*/
# define IS_ALPHA(x) ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) ? 1 : 0
# define IS_DIGIT(x) (x >= '0' && x <= '9') ? 1 : 0
# define IS_ALNUM(x) (IS_ALPHA(x) || IS_DIGIT(x)) ? 1 : 0
# define IS_ASCII(x) (x >= 0 && x <= 127) ? 1 : 0
# define IS_PRINT(x) (x >= 32 && x <= 126) ? 1 : 0
# define IS_ODD(x) (x) & 1
# define IS_EVEN(x) !IS_ODD(x)
# define IS_BIG_ENDIAN() (((*(short*)"21") & 0xFF) == '1')
# define IS_LITTLE_ENDIAN() (((*(short*)"21") & 0xFF) == '2')
# define GET_ARR_LEN(x) sizeof(x) / sizeof(x[0])
/*
** Switches
*/
# define TO_LOWER(x) (x | ' ')
# define TO_UPPER(x) (x & '_')
# define SWITCH_CASE(x) (x ^ ' ')
/*
** Math
*/
# define MIN(x, y) x < y ? x : y
# define MAX(x, y) x > y ? x : y
# define ABS(x) x >= 0 ? x : -x
# define SQUARE(x) x * x
/*
** Conditionals
*/
# define IF_TRUE(x, y) if (x) y
# define IF_FALSE(x, y) if (!x) y
# define IF_EXISTS(x, y) if (x) y
/*
** Bitwise Operations
*/
# define BIT_RL32(x, c) ((x << c) | (x >> (32 - c)))
# define BIT_RR32(x, c) ((x >> c) | (x << (32 - c)))
# define BIT_RL64(x, c) ((x << c) | (x >> (64 - c)))
# define BIT_RR64(x, c) ((x >> c) | (x << (64 - c)))

#endif
