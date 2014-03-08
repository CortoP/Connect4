/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:22:22 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 10:33:06 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			display(char **grid)
{
	int			i;
	int			j;
	int			sizeline;

	sizeline = ft_strlen(grid[0]);
	i = -1;
	while (grid[++i])
	{
		j = -1;
		ft_putchar('|');
		while (grid[i][++j])
			ft_putchar(grid[i][j]);
		ft_putstr("|\n");
	}
	ft_putchar(' ');
	i = 0;
	while (i < sizeline)
	{
		ft_putnbr(i % 10);
		i++;
	}
	ft_putchar('\n');
}
