#include "tetromino.h"
#include "fillit.h"

size_t	g_mino_ct = 0;

void	rd_input(const int fd, char *buff)
{
	int		rc;

	if (fd < 0 || BUFF_SIZE <= 0)
		return ;

	while (1)
	{
		if ((rc = read(fd, buff, BUFF_SIZE)) == 0)
			break;
	}
	if (rc == -1)
		return ;
}

char	**buff_to_raw_minos(int const fd)
{
	char	input[INPUT_MAX];
	char	**raw_minos;
	size_t	head;
	size_t	i;

	rd_input(fd, input);
	g_mino_ct = ft_strlen(input) / 21;
	head = 0;
	i = 0;
	raw_minos = ft_memalloc(sizeof(char *) * (g_mino_ct + 1));
	while (i < g_mino_ct)
	{
		raw_minos[i]= ft_strsub(input, head, 21);
		head = head + 21;
		i++;
	}
	return (raw_minos);
}

t_mino	**raw_minos_to_minos(size_t g_mino_ct, char **raw_minos)
{
	size_t	i;
	t_mino	*mino;
	t_mino	**minos;

	i = 0;
	mino = NULL;
	minos = ft_memalloc(sizeof(t_mino *) * g_mino_ct);
	while (raw_minos[i])
	{
		minos[i] = str_to_mino(raw_minos[i]);
		i++;
	}
	return (minos);
}
