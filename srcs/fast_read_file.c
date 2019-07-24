#include "bsq.h"

typedef struct		s_list
{
	void			*data;
	size_t			size;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *data, size_t size)
{
	t_list	*res;
	size_t	i;

	res = NULL;
	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(res->data = malloc(size)))
	{
		free(res);
		return (NULL);
	}
	i = 0;
	while (i < size)
		((char *)res->data)[i++] = *((char *)data++);
	res->size = size;
	return (res);
}

void	ft_lstadd(t_list **alst, t_list *lst)
{
	lst->next = *alst;
	*alst = lst;
}

void	ft_lstdel(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp = (*lst)->next;
		free((*lst)->data);
		(*lst)->data = NULL;
		free(*lst);
		*lst = NULL;
	}
}

void	ft_memcpy(void *dst, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		((char *)dst)[i++] = *(char *)src++;
}

char	*list_to_str(t_list **lst, size_t size)
{
	char	*res;
	t_list	*tmp;

	res = NULL;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
	{
		ft_lstdel(lst);
		return (NULL);
	}
	res[size] = '\0';
	while (size)
	{
		size -= (*lst)->size;
		ft_memcpy(res + size, (*lst)->data, (*lst)->size);
		tmp = (*lst)->next;
		free((*lst)->data);
		free(*lst);
		*lst = tmp;
	}
	return (res);
}

char	*fast_read_file(int fd)
{
	int		ret;
	char	buf[BUFF_SIZE];
	size_t	size;
	t_list	*lst;
	t_list	*elem;

	size = 0;
	lst = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (!(elem = ft_lstnew(buf, (size_t)ret)))
		{
			ft_lstdel(&lst);
			return (NULL);
		}
		ft_lstadd(&lst, elem);
		size += (size_t)ret;
	}
	return (list_to_str(&lst, size));
}
