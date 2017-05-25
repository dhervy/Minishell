/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:12:09 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/06 21:17:50 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_envu(t_all *all, int i)
{
	int		j;

	j = 0;
	while (all->tab[i][j] != '=' && all->tab[i][j] != '\0')
		j++;
	if (all->tab[i][j] == '=')
	{
		ft_putstr("env: unsetenv ");
		ft_putstr(all->tab[i]);
		ft_putstr(": Invalid argument\n");
		i = ft_tablen(all->tab);
	}
	else
		all->envcpy = ft_removenv(all->envcpy, all->tab[i]);
	return (i + 1);
}

void	ft_envi(t_all *all)
{
	int		j;

	j = 0;
	while (all->envcpy[j])
	{
		ft_bzero(all->envcpy[j], ft_strlen(all->envcpy[j]));
		free(all->envcpy[j]);
		j++;
	}
	free(all->envcpy);
	all->envcpy = (char**)ft_memalloc(sizeof(char*) * 2);
}

int		ft_env(t_all *all, int i)
{
	int		j;
	char	*str;

	j = 0;
	if (!ft_strcmp(all->tab[i], "env") && all->tab[i + 1][0] != '-')
		return (i + 1);
	while (all->tab[i][j] != '=' && j < ft_strlen(all->tab[i]))
		j++;
	if (j < ft_strlen(all->tab[i]))
	{
		str = ft_strndup(all->tab[i], j);
		all->envcpy = ft_addenv(all->envcpy, str, &all->tab[i][j + 1]);
		free(str);
	}
	else
	{
		ft_exec(all, &all->tab[i], all->envcpy);
		i = ft_tablen(all->tab);
	}
	return (i + 1);
}
