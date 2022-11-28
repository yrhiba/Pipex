/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:03:58 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/28 06:29:52 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define PNULL "(null)"
# define UPPRX "0X"
# define LWPRX "0x"
# define UPHEX "0123456789ABCDEF"
# define LWHEX "0123456789abcdef"

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_list_gn
{
	char				*content;
	int					fd;
	struct s_list_gn	*next;
}						t_list_gn;

typedef struct s_print
{
	va_list				args;
	int					error;
	int					width;
	int					mines;
	int					zero;
	int					point;
	int					hash;
	int					space;
	int					plus;
	int					w_nbr;
	int					p_num;
	int					buflen;
	char				*buff;
}						t_print;

int						ft_strlc(char *s, int len0_or_chr1);
char					*ft_fjoin(char *s1, char *s2);
char					*get_next_line(int fd);
t_list_gn				*ft_flstnew(char *content, int fd);
char					*ft_get_content(t_list_gn **list_o, int fd);
void					delete_node(t_list_gn **list, int fd);

int						ft_miniatoi(const char *str);
int						ft_isnum(int c);
char					*ft_itoa(long long n);

char					*ft_converthex(unsigned long n, const char *base);
int						ft_skip_num(const char *format, int i);

char					*ft_mins_s(char *s, t_print *tab);
char					*ft_precision_s(char *s, t_print *tab);
char					*ft_zerospaces_s(char *s, int c, int t_len);

int						ft_printf(const char *format, ...);

int						ft_format(const char *format, int i, t_print *tab);

void					ft_init_tab(t_print *tab);

int						ft_addchar(t_print *tab, char c);
int						ft_addnchar(char c, int len, t_print *tab);
int						ft_addstr(const char *s, t_print *tab);

int						ft_check_flags(const char *format, int index,
							t_print *to_print);

int						ft_fcheck_width(const char *format, int *i,
							t_print *tab);
int						ft_fcheck_zero(const char *format, int *i,
							t_print *tab);
int						ft_fcheck_mins(const char *format, int *i,
							t_print *tab);
int						ft_fcheck_point(const char *format, int *i,
							t_print *tab);
int						ft_fcheck_hash(const char *format, int *i,
							t_print *tab);
int						ft_fcheck_space(const char *format, int *i,
							t_print *tab);
int						ft_fcheck_plus(const char *format, int *i,
							t_print *tab);

int						ft_check_format(const char *format, int i,
							t_print *tab);

void					ft_format_c(t_print *tab, int c);
int						ft_format_s(t_print *tab);
char					*ft_format_s_usingflags(char *s, t_print *tab);
int						ft_format_d(t_print *tab);
char					*ft_format_d_usingflags(char *nbr, t_print *tab);
int						ft_format_u(t_print *tab);
int						ft_format_x(t_print *tab, const char *base,
							const char *suff);
char					*ft_format_x_usingflags(char *nbr, t_print *tab,
							const char *prefix, int f);
int						ft_format_p(t_print *tab);

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
size_t					ft_strlen(const char *s);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t len);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
void					*ft_calloc(size_t count, size_t size);
char					*ft_strdup(const char *s1);
int						ft_atoi(const char *str);
int						ft_tolower(int c);
int						ft_toupper(int c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

#endif
