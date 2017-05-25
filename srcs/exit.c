/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:31:53 by dhervy            #+#    #+#             */
/*   Updated: 2016/09/29 21:04:24 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exitshell(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	if (!ft_strcmp(tab[0], "exit"))
	{
		if (i <= 1)
			exit(0);
		else
			ft_putendl_fd("exit: too many arguments\n", 2);
	}
}
