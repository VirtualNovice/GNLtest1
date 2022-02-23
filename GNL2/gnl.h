#ifndef GNL_H
# define GNL_H

#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

