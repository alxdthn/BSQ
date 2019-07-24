#include "bsq.h"

int		ft_puterr(int ret)
{
	write(2, "map error\n", 10);
	return (ret);
}
