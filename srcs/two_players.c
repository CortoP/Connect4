/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:37:10 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 15:06:59 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <puissance_4.h>

void			two_players(char **grid, int line, int col)
{
	int			token;
	int			i;

	display(grid);
	i = -1;
	while (++i < line * col)
	{
		if (i % 2 == 0)
			token = get_token(ft_strlen(grid[0]) + 1, 'X');
		else
			token = get_token(ft_strlen(grid[0]) + 1, 'O');
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
}
