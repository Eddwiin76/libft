/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:24:24 by tpierre           #+#    #+#             */
/*   Updated: 2021/06/28 16:15:17 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
** IO FUNCTIONS
*/

void				ft_putadr_fd(unsigned long nbr, int fd);
void				ft_putadr(unsigned long nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char *s, int fd);
void				ft_putendl(char *s);
void				ft_puthexa_fd(unsigned int nbr, int fd);
void				ft_puthexa(unsigned int nbr);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr(char *s);
void				ft_putuhexa_fd(unsigned int nbr, int fd);
void				ft_putuhexa(unsigned int nbr);
void				ft_putunbr_fd(unsigned int nbr, int fd);
void				ft_putunbr(unsigned int nbr);

/*
** LIST FUNCTIONS
*/

void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void*));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

/*
** MEMORY FUNCTIONS
*/

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				ft_free_null(void *ptr);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, int size, int newsize);

/*
** STRING FUNCTIONS
*/

long				ft_atoi_long(const char *str);
int					ft_atoi(const char *str);
int					ft_isalldigit(char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isnumeric(char *str);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_sort_int_tab(int *tab, int size);
char				**ft_split(char const *s, char c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strcountchar(char *str, char c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdelchar(char *src, char c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_tabdel(void **tab);
size_t				ft_tabmaxlen(char **tab);
size_t				ft_tabsize(char **tab);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
