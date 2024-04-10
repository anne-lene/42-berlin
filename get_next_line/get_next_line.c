#include "get_next_line.h"

int	ft_read_buffer(int fd, char	**buffer)
{
	int	bytes_read;

	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read == 0)
		return (0);
	if (bytes_read < 0)
	{
        free(*buffer);
        *buffer = NULL;
        return (-1);
    }
	(*buffer)[bytes_read] = '\0';
	return (bytes_read);
}

static char	*ft_read_and_append(int fd, char *stash)
{
	char	*buffer;
	int	bytes_read; 
	
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while ((bytes_read = ft_read_buffer(fd, &buffer)) > 0)
	{
		stash = ft_strjoin(stash, buffer);
		if (ft_idx_after_newline(buffer) != -1)
			break ;
	}
	if (bytes_read < 0)
		return (free(stash), NULL);	
	free(buffer);
	return (stash);
}

char *ft_create_line(char *stash)
 {
    char *line;
    int i;
    int len = 0;

    i = 0;
	if (!stash[i])
        return (NULL);
	len = ft_idx_after_newline(stash) + 1;
    if (len == 0)
		len = ft_strlen(stash);
	line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
    while (stash[i] != 0 && stash[i] != '\n')
	{
        line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
	{
        line[i] = stash[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char	*ft_update_remainder(char *stash)
{
    char	*remainder; 
	int	j;
	int	idx;

	idx = ft_idx_after_newline(stash);
	if (idx < 0)
		return (free(stash), (NULL));
	remainder = (char *)ft_calloc((ft_strlen(stash) - idx + 1), sizeof(char));
	if (!remainder)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	idx++;
	while (stash[idx + j])
	{
		remainder[j] = stash[idx + j];
		j++;
	}
	remainder[j] = '\0';
	free(stash);
	return (remainder);
}

char  *get_next_line(int fd)
{
	static char	*stash = NULL;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
			free (stash);
		stash = NULL;
		return (NULL);
	}
	if (!stash)
		stash = (char *)ft_calloc(1, sizeof(char));
	if (!stash)
		return (NULL);
	stash = ft_read_and_append(fd, stash);
	line = ft_create_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_update_remainder(stash);
	return (line);
}