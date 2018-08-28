/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:48:59 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/27 08:00:08 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>

# define TRUE		1
# define FALSE		0
# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define PURPLE		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define GREY		"\033[1;37m"
# define DEFAULT	"\033[0;m"
# define BGG		"\e[48;5;45m"
# define WTC		"\e[38;5;45m"
# define BLOCK		"\e[48;5;25m "
# define NL			ft_putstr("\n");
# define CL			"\e[1;1H"
# define CLEA		"\e[1;1H\e[2J"

# include "get_next_line.h"

# define BUFF_SIZE_C 4096

/*
** IS FUNCTIONS
*/

size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_str_is_alpha(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_uppercase(char *str);

/*
** STRING MANIPULATON
*/

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const	*s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strspn(const char *s1, const char *s2);
size_t				ft_strcspn(const char *s1, const char *s2);
char				*ft_strtok(char *str, const char *delim);
char				*ft_strcleanjoin(char *s1, const char *s2);
char				*ft_strjoinc_clr(char *a, char b);
char				*ft_strjoin_clr(char *a, char *b, int d);
int					ft_strindexchr(char const *s, char c);
char				*ft_strbetween(const char *s, char a, char b);
int					ft_strpbrk_pos(const char *s, const char *charset);
char				*ft_strpbrk(const char *s, const char *charset);
char				*ft_itoa(int n);
char				*ft_itoa_base(int val, int base);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strmdup(const char *a, size_t n);
size_t				ft_arrsize(char **arr);

/*
** MEMORY FUNCTIONS
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memjoin(const void *a,
							size_t an,
							const void *b,
							size_t bn);
void				*ft_memjoin_clr(void *a,
						size_t an,
						void *b,
						size_t bn);
void				*ft_memdup(const void *src, size_t len);

/*
** PRINT FUNCTIONS
*/

int					ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
int					ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_printf(const char *format, ...);

/*
** LINKED LIST
*/

typedef struct		s_list
{
	void			*data;
	size_t			data_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t data_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** DOUBLY LINKED LIST
*/

typedef struct		s_dlist
{
	char			*data;
	size_t			data_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist				*ft_dlstnew(void const *content, size_t data_size);
t_dlist				*ft_dlstgethead(t_dlist *dlst);
t_dlist				*ft_dlstgettail(t_dlist *dlst);
void				ft_dlstadd(t_dlist **head, t_dlist *new);
void				ft_dlstaddback(t_dlist **head, t_dlist *new);
void				ft_dlstremoveif(t_dlist **head, int cmp());
void				ft_dlstremovenode(t_dlist **head);
size_t				ft_dlstsize(t_dlist *lst);

/*
** GET FUNCTIONS
*/
int					get_next_line(const int fd, char **line);
int					ft_getchar(void);

/*
** MATH FUNCTIONS
*/

float				ft_rsqrt(float number);

#endif
