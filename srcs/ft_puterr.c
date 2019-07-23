#include "bsq.h"

int		ft_puterr(int ret)
{
	write(2, "Error\n", 6);
	return (ret);
}
