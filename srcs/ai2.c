/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 17:07:48 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 18:26:15 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance_4.h>

int			test_adv3(char **grid)
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
			{
				ret = -5;
//				display(grid);
			}
			else
				ret = 4;
			grid[coord[0] - 1][coord[1]] = '.';
		}
		coord[1] = coord[1] + 1;
		if (ft_abs(ret) > ft_abs(tmp))
			tmp = ret;
	}
	return (tmp);
}

int			test_ai2(char **grid)
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
				return (6);
			}
			else
				coord[2] = test_adv3(grid);
			grid[coord[0] - 1][coord[1]] = '.';
		}
		if (ft_abs(coord[2]) > ft_abs(coord[3]))
			coord[3] = coord[2];
	}
	return (coord[3]);
}
