/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:27:19 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 18:04:54 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance_4.h>
#include <stdlib.h>

char		test_token(char **grid, int col)
{
	place_token(grid, col);
	if (test_win(grid, col) == 1)
		return (WIN);
	return (DRAW);
}

int			ai(char **grid, int cols)
{
	int		i;
	int		ret;
	int		tmp;
	int		tok;
	char	**copy;

	ret = -100000;
	i = 0;
	while (i < cols)
	{
		copy = tabdup(grid);
		tmp = test_token(copy, i);
		freetab(copy);
		if (tmp > ret)
		{
			ret = tmp;
			tok = i;
		}
		i++;
	}
	return (tok);
}
