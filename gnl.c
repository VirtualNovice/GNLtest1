//#include "gnl.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
# define FD_MAX 256
#include <string.h>
#define buf_size 10


void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			b;

	b = 0;
	a = s;
	while (b < n)
	{
		a[b] = 0;
		b++;
	}
}
int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (str == 0)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	size_t	a;

	a = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (a < n)
	{
		dest2[a] = src2[a];
		a++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		slen;
	char	*str;

	slen = ft_strlen(s);
	str = (char *)ft_calloc(slen + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, slen);
	return (str);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	char	*str;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[b] != '\0')
	{
		str[b] = s1[b];
		b++;
	}
	while (s2[a] != '\0')
	{
		str[b + a] = s2[a];
		a++;
	}
	str[b + a] = '\0';
	return (str);
}

int newline_checker(char *str) // check newline
{
	int a = 0;

	while(str[a] != '\0')
	{	
		if (str[a] == '\n')
		{
			return (a + 1);
		}
		a++;
	}
	return (0);
}

char *stash2(char *s, int size) // returning string until newline
{
	int a = 0;
	int s_size = ft_strlen(s);
	char *str = (char *)malloc(s_size * sizeof(char));
	while(a < size)
	{
		str[a] = s[a];
		a++;	
	}
	str[size] = '\0';
	return str;
}

char *get_next_line(int fd)
{
	char *buf = malloc(buf_size * sizeof(char));
	static char *stash;
	char *line = {0};
	int chker;
	char *stash3;
	int size;
    if (fd <= 0)
		return (NULL);
    if (!line)
		return (NULL);
	while (fd > 0)
	{
		if(stash == 0 || *stash == '\0') // stash is equal to 0 or '\0'
		{
			read(fd, buf, buf_size); // will read fd size of buf_size and transfer to buf
			stash = ft_strdup(buf); // copy the buf string to the static stash
		}
		else//f stash is not zero just copy stash to line
		{
			line = ft_strdup(stash);// copy stash to line
			free(stash);// free stash
		}
		chker = newline_checker(stash); // check if there is a newline in the stash and the number of char including \n
		stash3 = stash2(stash, chker); // transfering the string with \n 
		if (chker > 0)// check if the stash have new line
		{
			// if there is new line
			  stash = ft_strdup(stash + chker);// duplicates the remaining string after \n to static stash.
			  if(line != 0) // check if line is empty or not
				{
					// if is not empty
					line = ft_strjoin(line,stash3); // if it is not empty strjoin stash3 to line 
					return (line); // returning line, end of call
				}
				else
				{
					// else if empty
					line = ft_strdup(stash3);// duplicates the stash3 to line
					return (line);// returning line, end of call
				}
		}
		else
		{
			//if there is no newline
			  if(line != 0) // check if line is empty or not
				{
					// if is not empty
					line = ft_strjoin(line,stash);// if it is not empty strjoin stash3 to line.
					//free(stash);
					stash = 0; // free stash..emptying stash and setting it to 0,preparation for the nxt buf 
				}
				else
				{
					// else if empty
					line = ft_strdup(stash); // duplicates the stash3 to line
					//free(stash);
					stash = 0;// free stash..emptying stash and setting it to 0,preparation for the nxt buf  
				}	
		}
	}
	return NULL;//end of call	
}
int main(int argc, char *argv[])
{
        int fd;
        char *line;
		int a = 0;

        line = malloc(1 *sizeof(char));

        if (argc == 2)
        {
                fd = open(argv[1], O_RDONLY);
                while (line != NULL)
                {
                        free(line);
                        line = get_next_line(fd);
						int b = ft_strlen(line);
                        if (line == NULL)
                                exit(1);
				printf("line size = %d , line number = %d %s",b,a,line);
				a++;
                }
        }
	if (argc < 2)
	{
		while ((line = get_next_line(0)) != NULL)
		{
      			printf("Next line -> %s", line);
		}
	}
        return 0;
}
