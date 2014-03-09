/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:27:19 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 11:49:20 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance_4.h>
#include <stdlib.h>
#include <libft.h>

char		test_adv2(char **grid)
{
	int		line;
	int		ret;
	int		col;
	int		tmp;

	col = 0;
	tmp = 10;
	while (grid[0][col])
	{
		if (test_up(grid, col))
		{
			line = 0;
			while (grid[line] && grid[line][col] == '.')
				line++;
			grid[line - 1][col] = 'X';
			if (test_win(grid, col) == 1)
				ret = 1;
			else
				ret = 8;
			grid[line - 1][col] = '.';
		}
		col++;
		if (ret < tmp)
			tmp = ret;
	}
	return (tmp);
}

char		test_ai(char **grid)
{
	int		line;
	int		ret;
	int		col;
	int		tmp;

	col = 0;
	tmp = 10;
	while (grid[0][col])
	{
		if (test_up(grid, col))
		{
			line = 0;
			while (grid[line] && grid[line][col] == '.')
				line++;
			grid[line - 1][col] = 'O';
			if (test_win(grid, col) == 1)
			{
				grid[line - 1][col] = '.';
				return (9);
			}
			else
				ret = test_adv2(grid);
			grid[line - 1][col] = '.';
		}
		col++;
		if (ret < tmp)
			tmp = ret;
	}
	return (tmp);
}

char		test_adv(char **grid)
{
	int		line;
	int		ret;
	int		col;
	int		tmp;

	col = 0;
	tmp = 10;
	while (grid[0][col])
	{
		if (test_up(grid, col))
		{
			line = 0;
			while (grid[line] && grid[line][col] == '.')
				line++;
			grid[line - 1][col] = 'X';
			if (test_win(grid, col) == 1)
				ret = 0;
			else
				ret = test_ai(grid);
			grid[line - 1][col] = '.';
		}
		col++;
		if (ret < tmp)
			tmp = ret;
	}
	return (tmp);
}

char		test_token(char **grid, int col, char token)
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
	display(grid);
	grid[line - 1][col] = '.';
	return (ret);
}

int			ai(char **grid, int cols)
{
	int		i;
	int		ret;
	int		tmp;
	int		tok;

	ret = -100000;
	i = 0;
	while (i < cols)
	{
		if (test_up(grid, i) == 1)
		{
			tmp = test_token(grid, i, 'O');
			ft_putchar('\n');
			ft_putnbr(tmp);
			ft_putchar('\n');
			if (tmp > ret)
			{
				ret = tmp;
				tok = i;
			}
		}
		i++;
	}
	ft_putchar('\n');
	ft_putnbr(ret);
	ft_putchar('\n');
	return (tok);
}