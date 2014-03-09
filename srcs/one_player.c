/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:38:59 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 13:34:52 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <puissance_4.h>
#include <stdlib.h>
#include <time.h>

void			victory(char **grid, int col)
{
	int			l;

	l = 0;
	while (grid[l] && grid[l][col] == '.')
		l++;
	ft_putchar(grid[l][col]);
	ft_putendl(" win");
}

char			who_begin(void)
{
	srand(time(NULL));
	if (rand() % 2 == 0)
		return (-1);
	return (0);
}

void			one_player(char **grid, int line, int col)
{
	int			token;
	int			i;

	i = who_begin();
	display(grid);
	while (++i < line * col)
	{
		if (i % 2 == 1)
			token = ai(grid, col);
		else
			token = get_token(ft_strlen(grid[0]) + 1);
		if (token > -1)
		{
			grid = place_token(grid, token, i);
			display(grid);
			if (test_win(grid, token) == 1)
			{
				victory(grid, token);
				return ;
			}
		}
		else
			i--;
	}
	ft_putendl("\n\nMatch nul\n");
}
