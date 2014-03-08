/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:17:46 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 09:36:43 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
	if (test_num(lines) == 0)
		return (NULL);
	if (test_num(columns) == 0)
		return (NULL);
	ft_putstr("Yeaaah\n");
	return (NULL);
}
