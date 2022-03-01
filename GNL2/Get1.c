#include "gnl.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <string.h>
#define buf_size 5

int newline_checker(char *str)
{
	int a = 0;

	while(str[a] != '\0')
	{	
		if (str[a] == '\n')
		{
			return (a);
		}
		a++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	char *buf = malloc(fd * sizeof(char));
	static char *stash;
	char *stash2;
	char *line;
	int a = 0;
	int chker;

	while (stash == 0 || fd > 0)
	{
		if(stash == 0)
		{
			read(fd, buf, buf_size);
			stash = ft_strdup(buf);
		}

		chker = newline_checker(stash);

		if (chker > 0)
		{
			ft_memcpy(stash2, stash, chker);
			stash = ft_strdup(stash + chker);
			line = ft_strjoin(line, stash2);
		}
		else
		{
			line = ft_strjoin(line,stash);
		}
	}
	return line;	
}

int main(int argc, char *argv[])
{
	int fd;
	
	fd = open("oliver.txt", O_RDONLY);//should be same folder

	printf("%s",get_next_line(fd));
	return(0);
}
