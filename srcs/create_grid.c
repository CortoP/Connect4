/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:17:46 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 15:23:28 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		*fill_line(char *line, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		line[i] = '.';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char		**init_grid(int lines, int columns)
{
	char		**grid;
	int			i;

	if (!(grid =(char **)malloc(sizeof(char *) * (columns + 1))))
		return (NULL);
	grid[columns] = NULL;
	i = 0;
	while (i < lines)
	{
		if (!(grid[i] =(char *)malloc(sizeof(char *) * (lines + 1))))
			return (NULL);
		grid[i] = fill_line(grid[i], lines);
		i++;
	}
	return (grid);
}

int				test_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (ft_atoi(str));
}

char			**create_grid(char *lines, char *columns)
{
	char		**grid;
	int			l;
	int			c;

	if ((l = test_num(lines)) == -1)
		return (NULL);
	if ((c = test_num(columns)) == -1)
		return (NULL);
	if (c < 4 || c > 50)
		return (NULL);
	if (l < 4 || l > 50)
		return (NULL);
	if (!(grid = init_grid(l, c)))
		return (NULL);
	return (grid);
}
