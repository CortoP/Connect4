/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:13:09 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 13:41:21 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance_4.h>
#include <libft.h>

void		error(void)
{
	write(1, "Usage : ./puissance_4 [0-9] [0-9]\n", 34);
}

int			main(int ac, char **av)
{
	char	**grid;

	grid = NULL;
	if (ac == 3)
	{
		if (!(grid = create_grid(av[1], av[2])))
			error();
		else
			one_player(grid, ft_atoi(av[1]), ft_atoi(av[2]));
	}
	else
		error();
	if (grid)
		freetab(grid);
	return (0);
}
