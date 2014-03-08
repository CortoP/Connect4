/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:37:10 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 11:10:51 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <puissance_4.h>

void			two_players(char **grid)
{
	int			token;
	int			i;

	i = 0;
	while (i < 50)
	{
		token = get_token(ft_strlen(grid[0]));
		if (token > -1)
			grid = place_token(grid, token);
		display(grid);
		i++;
	}
	// test_win(grid);
}
