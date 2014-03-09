/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:27:19 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 18:44:18 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance_4.h>
#include <stdlib.h>
#include <libft.h>

int			test_adv2(char **grid)
{
	int		coord[2];
	int		ret;
	int		tmp;

	coord[1] = 0;
	tmp = 0;
	while (grid[0][coord[1]])
	{
		if (test_up(grid, coord[1]))
		{
			coord[0] = 0;
			while (grid[coord[0]] && grid[coord[0]][coord[1]] == '.')
				coord[0]++;
			grid[coord[0] - 1][coord[1]] = 'X';
			if (test_win(grid, coord[1]) == 1)
				ret = -7;
			else
				ret = 6;
			grid[coord[0] - 1][coord[1]] = '.';
		}
		coord[1] = coord[1] + 1;
		if (ft_abs(ret) > ft_abs(tmp))
			tmp = ret;
	}
	return (tmp);
}

int			test_ai(char **grid)
{
	int		coord[4];

	coord[1] = -1;
	coord[3] = 0;
	while (grid[0][++coord[1]])
	{
		if (test_up(grid, coord[1]))
		{
			coord[0] = 0;
			while (grid[coord[0]] && grid[coord[0]][coord[1]] == '.')
				coord[0]++;
			grid[coord[0] - 1][coord[1]] = 'O';
			if (test_win(grid, coord[1]) == 1)
			{
				grid[coord[0] - 1][coord[1]] = '.';
				return (8);
			}
			else
				coord[2] = test_adv2(grid);
			grid[coord[0] - 1][coord[1]] = '.';
		}
		if (ft_abs(coord[2]) > ft_abs(coord[3]))
			coord[3] = coord[2];
	}
	return (coord[3]);
}

int			test_adv(char **grid)
{
	int		coord[2];
	int		ret;
	int		tmp;

	coord[1] = 0;
	tmp = 0;
	while (grid[0][coord[1]])
	{
		if (test_up(grid, coord[1]))
		{
			coord[0] = 0;
			while (grid[coord[0]] && grid[coord[0]][coord[1]] == '.')
				coord[0]++;
			grid[coord[0] - 1][coord[1]] = 'X';
			if (test_win(grid, coord[1]) == 1)
				ret = -9;
			else
				ret = test_ai(grid);
			grid[coord[0] - 1][coord[1]] = '.';
		}
		coord[1]++;
		if (ft_abs(ret) > ft_abs(tmp))
			tmp = ret;
	}
	return (tmp);
}

int			test_token(char **grid, int col, char token)
{
	int		line;
	int		ret;

	if (grid[0][col] != '.')
		return (0);
	line = 0;
	while (grid[line] && grid[line][col] == '.')
		line++;
	grid[line - 1][col] = token;
	if (test_win(grid, col) == 1)
		ret = 10;
	else
		ret = test_adv(grid);
	grid[line - 1][col] = '.';
	return (ret);
}

int			ai(char **grid, int cols)
{
	int		i;
	int		ret;
	int		tmp;
	int		tok;

	ret = 0;
	i = 0;
	while (i < cols)
	{
		if (test_up(grid, i) == 1)
		{
			tmp = test_token(grid, i, 'O');
				ft_putnbr(i);
				ft_putchar(' ');
				ft_putnbr(tmp);
				ft_putchar('\n');
				if (tmp >= ret)
				{
					ret = tmp;
					tok = i;
				}
		}
		i++;
	}
	return (tok);
}
