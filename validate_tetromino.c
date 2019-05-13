/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetromino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwhitlow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:47:47 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/12 20:46:56 by nwhitlow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

static int	is_solid(char *input, int i)
{
	if (i < 0)
		return (0);
	return (input[i] == '#');
}

static int	check_tile(char *input, int i, int *connections, int *solids)
{
	if (i % 5 == 4 || i == 20)
	{
		if (input[i] != '\n')
			return (0);
	}
	else
	{
		if (input[i] == '#')
		{
			*solids += 1;
			*connections += is_solid(input, i - 1);
			*connections += is_solid(input, i - 5);
			return (1);
		}
		else if (input[i] != '.')
			return (0);
	}
	return (1);
}

char		*str_to_tetromino(char *input)
{
	int		i;
	int		connections;
	int		solids;
	char	*tetromino;

	i = 0;
	connections = 0;
	solids = 0;
	while (i < 21)
	{
		if (!check_tile(input, i, &connections, &solids))
			return (NULL);
		i++;
	}
	if (solids != 4 || connections < 3)
		return (NULL);
	tetromino = (char *)malloc(16 * sizeof(char));
	if (!tetromino)
		return (NULL);
	ft_memcpy(tetromino, input, 4);
	ft_memcpy(tetromino + 4, input + 5, 4);
	ft_memcpy(tetromino + 8, input + 10, 4);
	ft_memcpy(tetromino + 12, input + 15, 4);
	return (tetromino);
}
