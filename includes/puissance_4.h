/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance_4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:31:47 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 11:33:27 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_4_H
# define PUISSANCE_4_H

char		**create_grid(char *lines, char *columns);
int			test_num(char *str);
void		display(char **grid);
void		two_players(char **grid);
int			get_token(int sizeline);
char		**place_token(char **grid, int token);
char		test_win(char **grid, int column);

#endif /* !PUISSANCE_4_H */
