/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:04:44 by hnewman           #+#    #+#             */
/*   Updated: 2021/04/25 16:59:59 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 26

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
void				*ft_memset(void *s, int ch, size_t n);
void				*ft_memcpy(void *dest, void *src, size_t n);
void				*ft_memccpy(void *dest, void *src, int ch, size_t n);
void				*ft_memmove(void *dest, void *src, size_t n);
void				*ft_memchr(void *arr, int ch, size_t n);
int					ft_memcmp(void *s1, void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_isprint(int ch);
int					ft_isalnum(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
int					ft_isascii(int ch);
size_t				ft_strlen(char const *str);
int					ft_isdigit(int ch);
int					ft_isalpha(int ch);
int					ft_atoi(char *str);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strnstr(char *str, char *to_find, size_t len);
char				*ft_strrchr(char *str, int ch);
char				*ft_strchr(char *str, int ch);
char				*ft_strdup(char *src);
void				*ft_calloc(size_t n, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
