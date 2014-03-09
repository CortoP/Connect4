/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance_4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 09:31:47 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/09 13:34:45 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_4_H
# define PUISSANCE_4_H

#define WIN 1
#define DRAW 0
#define FAIL -1

typedef struct	s_tok
{
	int			col;
	int			pts;
}				t_tok;

char		**create_grid(char *lines, char *columns);
int			test_num(char *str);
void		display(char **grid);
void		two_players(char **grid, int line, int col);
void		one_player(char **grid, int line, int col);
int			get_token(int sizeline);
char		**place_token(char **grid, int token, int i);
char		test_win(char **grid, int column);
char		**tabdup(char **tab);
void		freetab(char **tab);
int			ai(char **grid, int col);
char		test_up(char **grid, int col);
#endif /* !PUISSANCE_4_H */
