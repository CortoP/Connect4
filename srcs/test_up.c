/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 10:16:56 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 10:26:57 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		test_up(char **grid, int col)
{
	if (grid[0][col] == '.')
		return (1);
	return (0);
}
