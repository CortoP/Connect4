/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:38:59 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 13:05:23 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <puissance_4.h>

void			one_player(char **grid, int line, int col)
{
	int			token;
	int			i;
	int			k;

	i = -1;
	display(grid);
	while (++i < line * col)
	{
		if (i % 2 == 1)
			token = ai(grid, col);
//			token = get_token(ft_strlen(grid[0]) + 1);
		else
			token = get_token(ft_strlen(grid[0]) + 1);
		if (token > -1)
		{
			grid = place_token(grid, token);
			display(grid);
			if (test_win(grid, token) == 1)
			{
				k = 0;
				while (grid[k] && grid[k][token] == '.')
					k++;
				ft_putchar(grid[k][token]);
				ft_putendl(" win");
				return ;
			}
		}
		else
			i--;
	}
	ft_putendl("\n\nMatch nul\n");
}
