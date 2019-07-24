#include "bsq.h"


void	ft_bzero(void *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		((char *)src)[i++] = '\0';
}
