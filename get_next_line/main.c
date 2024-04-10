#include "get_next_line.h"

int	main()
{
	int	bytes_read;
	char	*str;
	int    fd;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("\n %s", str);
	str = get_next_line(fd);
	printf("\n %s", str);
	str = get_next_line(fd);
	printf("\n %s", str);
	str = get_next_line(fd);
	printf("\n %s", str);
	str = get_next_line(fd);
	printf("\n %s", str);
	str = get_next_line(fd);
	printf("\n %s", str);	
 	/*while ((str = get_next_line(fd)) != NULL)
	{
		printf("\n %s", str);
		free(str);
		str = NULL;
	}*/
	close(fd);
    return (0);
}