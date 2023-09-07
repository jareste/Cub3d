/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:45:12 by baltes-g          #+#    #+#             */
/*   Updated: 2023/08/31 17:39:16 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define NO 0
# define FIRST 1
# define SECOND 2
# define BOTH 3

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_flags
{
	int	content;
	int	space;
	int	hash;
	int	plus;
	int	aux;
}				t_flags;

void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcat(char *dest, char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_tolower(char *c);
int				ft_toupper(int c);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int				ft_atoi(char *str, int rm);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char *s1, int rm);
char			*ft_substr(char *s, unsigned int start, size_t len, int rm);
char			*ft_strjoin(char *s1, char *s2, int rm);
char			*ft_strtrim(char *s1, char *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_split(char *s, char *c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
char			*get_next_line(int fd);
char			*clean(char *to_clean);
char			*next_acc(char *accumulative);
char			*read_from_acc(char *accumulative);
char			*read_from_file(int fd, char *accumulative);
size_t			ft_strlen_gnl(const char *str);
char			*ft_strdup_gnl(char *s1);
char			*ft_strchr_gnl(char *s, int c);
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*ft_strrchr_gnl(const char *s, int c);
size_t			ft_strlen_gnl(const char *str);
int				ft_htoa_printf(t_flags flags, unsigned int c,
					int *error, int maj);
int				ft_itoa_printf(t_flags flags, int c, int *error);
int				ft_printchar_printf(t_flags flags, int c, int *error);
int				ft_printf(char const *str, ...);
int				ft_printstr_printf(t_flags flags, char *str, int *error);
int				ft_ptoa_printf(t_flags flags,
					unsigned long long int c, int *error);
int				ft_uitoa_printf(t_flags flags, unsigned int c, int *error);

#endif
