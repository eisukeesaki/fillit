#include "tetromino.h"
#include "fillit.h"

static void		read_input(const int fd, char *buff)
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

static char		**buff_to_raw_minos(size_t mino_ct, char *input)
{
	char	**raw_minos;
	size_t	head;
	size_t	i;

	head = 0;
	i = 0;
	raw_minos = ft_memalloc(sizeof(char *) * (mino_ct + 1));
	while (i < mino_ct)
	{
		raw_minos[i]= ft_strsub(input, head, 21);
		head = head + 21;
		i++;
	}
	return (raw_minos);
}

static t_mino	**raw_minos_to_minos(size_t mino_ct, char **raw_minos)
{
	size_t	i;
	t_mino	*mino;
	t_mino	**minos;
	char	letter;

	i = 0;
	mino = NULL;
	minos = ft_memalloc(sizeof(t_mino *) * mino_ct + 1);
	letter = 'A';
	while (raw_minos[i])
	{
		minos[i] = str_to_mino(raw_minos[i]);
		minos[i]->letter = letter;
		letter++;
		i++;
	}
	return (minos);
}

t_mino			**fd_to_minos(int const fd)
{
	char	input[INPUT_MAX];
	size_t	mino_ct;
	char	**split_minos;

	read_input(fd, input);
	mino_ct = ft_strlen(input) / 21;
	split_minos = buff_to_raw_minos(mino_ct, input);
	return (raw_minos_to_minos(mino_ct, split_minos));
}

