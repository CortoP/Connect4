/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 15:13:40 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 15:20:19 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance_4.h>

char		test_adv3(char **grid)
{
	int		coord[2];
	int		ret;
	int		tmp;

	coord[1] = 0;
	tmp = 10;
	while (grid[0][coord[1]])
	{
		if (test_up(grid, coord[1]))
		{
			coord[0] = 0;
			while (grid[coord[0]] && grid[coord[0]][coord[1]] == '.')
				coord[0]++;
			grid[coord[0] - 1][coord[1]] = 'X';
			if (test_win(grid, coord[1]) == 1)
				ret = 1;
			else
				ret = 7;
			grid[coord[0] - 1][coord[1]] = '.';
		}
		coord[1] = coord[1] + 1;
		if (ret < tmp)
			tmp = ret;
	}
	return (tmp);
}

char		test_ai2(char **grid)
{
	int		coord[4];

	coord[1] = -1;
	coord[3] = 10;
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
				coord[2] = test_adv3(grid);
			grid[coord[0] - 1][coord[1]] = '.';
		}
		if (coord[2] < coord[3])
			coord[3] = coord[2];
	}
	return (coord[3]);
}
