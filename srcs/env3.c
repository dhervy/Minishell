/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:12:05 by dhervy            #+#    #+#             */
/*   Updated: 2017/05/24 15:07:29 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_envshell3(t_all *all, int i, int *arg)
{
	if (arg[1] == 1)
	{
		arg[1] = 0;
		arg[0] = 0;
		ft_envi(all);
		i++;
	}
	else if (arg[0] == 1)
	{
		arg[0] = 0;
		i = ft_envu(all, i + 1);
	}
	return (i);
}

void	ft_initenvshell(t_all *all)
{
	int		i;
	int		j;
	int		arg[2];

	i = 0;
	j = 1;
	arg[0] = 0;
	arg[1] = 0;
	if (all->envcpy)
		ft_tabfree(all->envcpy);
	all->envcpy = ft_tabdup(all->env, ft_tablen(all->env) + 1);
	ft_envshell2(all, i, j, arg);
}

int		ft_envusage(t_all *all, int i, int j, int *arg)
{
	arg[1] = 0;
	arg[0] = 0;
	ft_putstr("env: illegal option -- ");
	ft_putchar(all->tab[i][j]);
	ft_putstr("\nusage: env [-iu] [Variable]\n");
	i = ft_tablen(all->tab);
	return (i);
}

int		ft_envshell5(t_all *all, int i, int j, int *arg)
{
	while (all->tab[i][j])
	{
		if (all->tab[i][j] == 'i')
			arg[1] = 1;
		else if (all->tab[i][j] == 'u')
			arg[0] = 1;
		else
		{
			i = ft_envusage(all, i, j, arg);
			break ;
		}
		j++;
		if (!all->tab[i][j] && all->tab[i + 1][0] == '-')
		{
			i++;
			j = 1;
		}
	}
	return (i);
}

void	ft_envshell2(t_all *all, int i, int j, int *arg)
{
	while (i < ft_tablen(all->tab))
	{
		j = 1;
		if (!ft_strcmp(all->tab[i], "env") && all->tab[i + 1][0] == '-')
		{
			i++;
			i = ft_envshell5(all, i, j, arg);
			i = ft_envshell3(all, i, arg);
		}
		else
			i = ft_env(all, i);
	}
}
