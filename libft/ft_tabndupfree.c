/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:12:51 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/06 17:23:33 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabndupfree(char **tab, int size, int n)
{
	char	**new;
	int		i;

	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * size);
	while (i < n)
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	ft_tabfree(tab);
	return (new);
}
