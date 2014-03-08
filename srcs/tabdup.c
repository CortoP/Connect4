/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:15:29 by vlehuger          #+#    #+#             */
/*   Updated: 2014/03/08 17:24:48 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char			**tabdup(char **tab)
{
	char		**copy;
	int			i;
	int			j;
	int			k;

	k = 0;
	while (tab[k])
		k++;
	if (!(copy = (char **)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	copy[k] = NULL;
	i = -1;
	while (++i < k)
	{
		if (!(copy[i] = (char *)malloc(sizeof(char *) * (ft_strlen(tab[i])))))
			return (NULL);
		j = -1;
		while (++j < (int)ft_strlen(tab[i]))
		{
			copy[i][j] = tab[i][j];
		}
		copy[j] = '\0';
	}
	return (copy);
}
