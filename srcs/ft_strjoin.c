#include "bsq.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char)
	* (ft_strlen(str1) + ft_strlen(str2) + 1))))
		return (NULL);
	if (str1)
		while (*str1)
			res[i++] = *(str1++);
	if (str2)
		while (*str2)
			res[i++] = *(str2++);
	res[i] = '\0';
	return (res);
}
