/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetromino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:47:47 by nwhitlow          #+#    #+#             */
/*   Updated: 2019/05/29 00:43:40 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_solid(char *input, int i)
{
	if (i < 0)
		return (0);
	return (input[i] == '#');
}

static int	validate(char *input, t_mino *tetromino, int *solids)
{
	int		i;

	i = 0;
	while (i < 21)
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
				tetromino->width += is_solid(input, i - 1);
				tetromino->height += is_solid(input, i - 5);
			}
			else if (input[i] != '.')
				return (0);
		}
		i++;
	}
	return (1);
}

static void	extract_pattern(char *input, t_mino *tetromino)
{
	char	padded[16];
	int		start;
	int		end;

	ft_memcpy(padded, input, 4);
	ft_memcpy(padded + 4, input + 5, 4);
	ft_memcpy(padded + 8, input + 10, 4);
	ft_memcpy(padded + 12, input + 15, 4);
	start = 0;
	while (ft_strnequ(padded + start, "....", 4))
		start += 4;
	while (1)
	{
		if (padded[start] == '#' || padded[start + 4] == '#')
			break ;
		if (padded[start + 8] == '#' || padded[start + 12] == '#')
			break ;
		start++;
	}
	end = 15;
	while (padded[end] == '.')
		end--;
	ft_memcpy(tetromino->pattern, padded + start, end - start + 1);
	tetromino->pattern[end - start + 1] = 0;
}

t_mino		*str_to_mino(char *input)
{
	int		solids;
	t_mino	*tetromino;

	tetromino = (t_mino *)malloc(sizeof(t_mino));
	if (!tetromino)
		return (NULL);
	tetromino->width = 1;
	tetromino->height = 1;
	solids = 0;
	if (!validate(input, tetromino, &solids))
		return (NULL);
	if (solids != 4 || tetromino->width + tetromino->height < 5)
		return (NULL);
	if (tetromino->width == tetromino->height)
	{
		tetromino->width = 2;
		tetromino->height = 2;
	}
	extract_pattern(input, tetromino);
	return (tetromino);
}
