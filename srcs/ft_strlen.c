#include "bsq.h"

size_t		ft_strlen(char *str)
{
	size_t 	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	else
		return (0);
}
