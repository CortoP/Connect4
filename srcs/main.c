/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:13:09 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 15:01:42 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance_4.h>
#include <libft.h>

void		error(void)
{
	write(1, "Usage : ./puissance_4 [0-9] [0-9]\n", 34);
}

char		player_choice(void)
{
	int		nb;
	char	*str;

	ft_putstr("1 ou 2 joueurs : ");
	get_next_line(0, &str);
	nb = test_num(str);
	if (nb == 1 || nb == 2)
		return (nb);
	else
		return (player_choice());
}

int			main(int ac, char **av)
{
	char	**grid;

	grid = NULL;
	if (ac == 3)
	{
		if (!(grid = create_grid(av[1], av[2])))
			error();
		else if (player_choice() == 1)
			one_player(grid, ft_atoi(av[1]), ft_atoi(av[2]));
		else
			two_players(grid, ft_atoi(av[1]), ft_atoi(av[2]));
	}
	else
		error();
	if (grid)
		freetab(grid);
	return (0);
}
