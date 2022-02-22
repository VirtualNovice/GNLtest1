#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>

#include <string.h>
#define buf_size 999

char *get_next_line(int fd)
{
	char *buf = malloc(fd * sizeof(char));
	
	read(fd, buf, buf_size);
	buf[buf_size] = '\0';
	return buf;	
}

/*void print(char *str, int a)
{
	int i = 0;
	while (i < a)
	{
		write(1, &str[i], 1);
		i++;
	}
}*/

int main(int argc, char *argv[])
{
	int fd;
	//char buf[buf_size + 1];
	//char *tst;
	
	fd = open("oliver.txt", O_RDONLY);//should be same folder
	//int size = strlen(fd);
	/*read(fd,buf,buf_size);
	buf[buf_size] = '\0';
	//close(fd);
	int size = strlen(buf);
	printf("%s size = %d ",buf,size);*/
	//tst = get_next_line(fd);
	//print(get_next_line(fd),999);
	printf("%s",get_next_line(fd));
	return(0);
}
