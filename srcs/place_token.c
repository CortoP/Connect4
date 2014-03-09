/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:55:55 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 13:34:35 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		**place_token(char **grid, int token, int i)
{
	int				line;

	if (grid[0][token] != '.')
		return (grid);
	line = 0;
	while (grid[line] && grid[line][token] == '.')
		line++;
	if (i % 2 == 0)
		grid[line - 1][token] = 'X';
	else
		grid[line - 1][token] = 'O';
	return (grid);
}
