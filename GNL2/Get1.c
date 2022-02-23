#include "gnl.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <string.h>
#define buf_size 5

char *get_next_line(int fd)
{
	char *buf = malloc(fd * sizeof(char));
	static char *stash;
	char *line;
	int a = 0;

	while (a != 999)
	{
		read(fd, buf, buf_size);
		stash = ft_strdup(buf);

		line = ft_strjoin(line,stash);
		a++;
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
