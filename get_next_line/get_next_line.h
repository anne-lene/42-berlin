#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int	ft_read_buffer(int fd, char	**buffer); // reads BUFFER SIZE CHARACHTERS INTO a string buffer
int ft_idx_after_newline(const char *str); // what if only \n? what if end of string reached already?
char *ft_create_line(char *stash);
char	*ft_update_remainder(char *stash);
char  *get_next_line(int fd);

#endif