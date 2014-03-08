/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:55:55 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 11:02:43 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		**place_token(char **grid, int token)
{
	int				line;
	static int		count = -1;

	count++;
	if (grid[0][token] != '.')
		return (grid);
	line = 0;
	while (grid[line] && grid[line][token] == '.')
		line++;
	if (count % 2 == 0)
		grid[line - 1][token] = 'X';
	else
		grid[line - 1][token] = 'O';
	return (grid);
}
