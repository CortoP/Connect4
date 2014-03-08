/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:13:09 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 09:39:04 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <puissance_4.h>
#include <unistd.h>

void		error(void)
{
	write(1, "Usage : ./puissance_4 [0-9] [0-9]\n", 34);
}

int			main(int ac, char **av)
{
//	int		player;
	char	**grid;

	if (ac == 3)
	{
		if ((grid = create_grid(av[1], av[2])) == NULL)
		{
			error();
		}
		//Nb de joueurs ?
/*		if (player == 1)
			ia();
		else if (player == 2)
			two_player();
*/
	}
	else
		error();
	return (0);
}
