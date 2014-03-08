/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:42:46 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 11:10:28 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <puissance_4.h>

int			get_token(int sizeline)
{
	char	*str;
	int		token;

	ft_putstr("New token : ");
	get_next_line(0, &str);
	token = test_num(str);
	if (token > 0 && token < sizeline)
		return (token - 1);
	return (-1);
}
