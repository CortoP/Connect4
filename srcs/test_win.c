/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:19:16 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 12:17:50 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	test_left_right(char **grid, int l, int c, char tok)
{
	int		i;
	int		count;
	int		save;

	save = 0;
	count = 0;
	if (c >= 3)
		i = c - 3;
	else
		i = 0;
	while (grid[l][i] && i <= c + 3)
	{
		if (grid[l][i] == tok)
			count++;
		if (count == 4)
			return (1);
		if (count == save)
			count = 0;
		save = count;
		i++;
	}
	return (0);
}

char	test_up_down(char **grid, int l, int c, char tok)
{
	int		i;
	int		count;
	int		save;

	save = 0;
	count = 0;
	if (l >= 3)
		i = l - 3;
	else
		i = 0;
	while (grid[i] && i <= l + 3)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putnbr(c);
		ft_putchar(' ');
		ft_putchar(grid[i][c]);
		ft_putchar('\n');

		if (grid[i][c] == tok)
			count++;
		if (count == 4)
			return (1);
		if (count == save)
			count = 0;
		save = count;
		i++;
	}
	return (0);
}

char		test_win(char **grid, int column)
{
	char	token;
	int		i;

	i = 0;
	while (grid[i] && grid[i][column] == '.')
		i++;
	token = grid[i][column];
	if (test_left_right(grid, i, column, token) == 1)
		return (1);
	if (test_up_down(grid, i, column, token) == 1)
		return (1);
/*	if (test_diag_up_left(grid, i, colmun, token) == 1)
		return (1);
	if (test_diag_up_right(grid, i, column, token) == 1)
		return (1);
*/	return (0);
}
