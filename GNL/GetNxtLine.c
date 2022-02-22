#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int fd;
	char buf[100];

	//write

	//int open(const char *pathname, int flags, mode_t mode);
	fd = open("oliver.txt", O_CREAT | O_WRONLY, 0600);//0600 = read and write only

	if (fd == -1)
	{
		printf("failed to create and open the file.\n");
		exit(1);
	}


	write(fd, "the quick brown\nfox jumps over the lazy dog", 99);
	close(fd);

	//read
	
	//int open(const char *pathname, int flags);
	fd = open("oliver.txt", O_RDONLY);
	
	if (fd == -1)
	{
		printf("Failed to open and read the file.\n");
		exit(1);
	}
	
	read(fd, buf, ^\n);
	buf[99] = '\0';

	close(fd);

	printf("buf: %s\n", buf);
	return(0);
}

