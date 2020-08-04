/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:16:04 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:54:24 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifdef __linux__
#  include <sys/types.h>
#  define LONG_LONG_MIN LLONG_MIN
#  define OPEN_MAX 1024
# endif

# define BUFF_SIZE 64
# define AND &&
# define OR ||

# define FT_INT_MIN -2147483648l
# define FT_INT_MIN_STR "-2147483648"
# define FT_INT_MAX 2147483647
# define FT_LONG_LONG_MIN_STR "-9223372036854775808"
# define FT_CHAR_MAX 128
# define FT_NULL 0
# define FT_SIZE_T_MAX  18446744073709551615u
# define FT_NEAR_LLONG_MAX 922337203685477580ul
# define ULLONG_MAX_DIGITS 80
# define FT_LONG_LONG_MIN LONG_LONG_MIN

# define FT_TRUE 1
# define FT_FALSE 0

typedef unsigned char		t_uchar;
typedef	unsigned long long	t_ull;

/*
 ** for_printf
*/
ssize_t			ft_strchri(const char *s, char c);
char			*ft_itoa_base(int value, char *buffer, int base, char a);
ssize_t			ft_str_find(const char *s, int (*f)(char ch));
char			*ft_uitoa_base(unsigned int value,
				char *buffer, int base, char a);
char			*ft_ulltoa_base(t_ull ull, char *str, int base, char a);
char			*ft_lltoa_base(long long ll, char *str, int base, char a);
ssize_t			ft_str_func_not_find(const char *s, int (*f)(char ch));
int				ft_min(int a, int b);
int				ft_max(int a, int b);
ssize_t			ft_strcspn(const char *s, const char *charset);

typedef struct	s_lldiv
{
	long long	qout;
	long long	rem;
}				t_lldiv;

typedef struct	s_ulldiv
{
	t_ull	qout;
	t_ull	rem;
}				t_ulldiv;

long			ft_atoi_l(const char *str);
int				ft_atoi(const char *str);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strdup(const char *src);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int,
						char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char
				(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int
				start, size_t len);
int				ft_strnequ(char const *s1, char const *s2,
				size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
char			*ft_itoa(int n);
void			ft_putnbr(int n);
char			*ft_strtrim(char const *s);
char			*ft_strtrimn(char const *s, char n);
char			**ft_strsplit(char const *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lst_pb(t_list **begin_list,
				void const *content, size_t content_size);
long int		ft_lstsize(t_list *begin_list);
char			*ft_strrev(char *str);
void			ft_swap(int *x, int *y);
long long		ft_pow(int number, int pow);
char			*ft_strjoin_free(char const *s1, char const *s2, int n);
int				ft_strchrn(const char *s, int c);
t_list			*ft_lstfind(t_list *lst,
				int (*finder)(void *, void *), void *to_find);
int				ft_get_next_line(int fd, char **line);
char			*ft_strsub_free(char const *s,
				unsigned int start, size_t len, short free_or_not);
void			ft_quicksort(int *arr, int low, int high);
void			ft_error(void);
void			ft_error_t(char const *text);
void			to_free_dstr(char **s);
int				word_counter(char const *str, char c);

#endif
