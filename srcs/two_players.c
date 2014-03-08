/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:37:10 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 14:16:50 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <puissance_4.h>

void			two_players(char **grid)
{
	int			token;
	int			i;
	char		tok;
	int			k;

	i = 0;
	while (i < 50)
	{
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
				tok = grid[k][token];
				ft_putchar(tok);
				ft_putendl(" win");
				return ;
			}
		}
		i++;
	}
}
