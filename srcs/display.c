/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:22:22 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 13:47:53 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			put_token(char c)
{
	if (c == 'X')
		ft_putstr("\033[0;33m""X""\033[00m");
	else if (c == 'O')
		ft_putstr("\033[0;31m""O""\033[00m");
	else
		ft_putchar(c);
}

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
		ft_putstr("\033[00;34m""|""\033[00m");
		while (grid[i][++j])
			put_token(grid[i][j]);
		ft_putstr("\033[00;34m""|\n""\033[00m");
	}
	ft_putchar(' ');
	i = 1;
	while (i <= sizeline)
	{
		ft_putnbr(i % 10);
		i++;
	}
	ft_putchar('\n');
}
