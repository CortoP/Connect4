/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:17:46 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 10:07:39 by vlehuger         ###   ########.fr       */
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
		ft_putchar(line[i]);
		i++;
	}
	ft_putchar('\n');
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

static char		test_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char			**create_grid(char *lines, char *columns)
{
	char		**grid;

	if (test_num(lines) == 0)
		return (NULL);
	if (test_num(columns) == 0)
		return (NULL);
	if (!(grid = init_grid(atoi(lines), atoi(columns))))
		return (NULL);
	return (grid);
}
