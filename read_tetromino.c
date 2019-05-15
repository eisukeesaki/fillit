#include "tetromino.h"
#include "libft/libft.h"
#define BUFF_SIZE 546

t_mino	*str_to_mino(char *input);

void	rd_input(const int fd, char *array)
{
	int		rc;

	if (fd < 0 || BUFF_SIZE <= 0)
		return ;
	while (1)
	{
		if ((rc = read(fd, array, BUFF_SIZE)) == 0)
			break;
	}
	if (rc == -1)
		return ;
}

size_t	count_mino(char *s)
{
	return (ft_strlen(s) % 20);
}

char	**init_array_of_minos(size_t n)
{
	char	**array;

	array = ft_memalloc((n + 1) * sizeof(char *));
	return (array);
}

char	**split_input(int const fd)
{
	char	raw_input[BUFF_SIZE];
	size_t	mino_ct;
	char	**minos;
	size_t	i;
	size_t	head;

	i = 0;
	head = 0;
	rd_input(fd, raw_input);
	mino_ct = ft_strlen(raw_input) % 20;
	minos = init_array_of_minos(mino_ct);
	while (i < mino_ct)
	{
		minos[i] = ft_strsub(raw_input, head, 21);
		i++;
		head = head + 21;
	}
	minos[i] = NULL;
	return (minos);
}
