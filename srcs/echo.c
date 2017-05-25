/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:44:33 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/18 19:34:44 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <signal.h>

void	sigfunc(int sig)
{
	char	pwd[4096];

	if (sig == SIGINT)
	{
		g_prompt = 1;
		ft_putchar('\n');
		ft_putstr(getcwd(pwd, 4096));
		ft_putstr(" $> ");
	}
}

void	ft_putprompt(t_all *all)
{
	ft_putstr(all->pwd);
	ft_putstr(" $> ");
}

int		ft_checkonlyspace(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_vartotab(t_all *all)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (all->tab[i])
	{
		if (all->tab[i][0] == '$')
		{
			if ((tmp = ft_searchenv(all->env, &all->tab[i][1])))
			{
				ft_strdel(&all->tab[i]);
				all->tab[i] = ft_strdup(tmp);
				return ;
			}
		}
		i++;
	}
}

void	ft_echoshell(t_all *all, int n, int i)
{
	if (!ft_strcmp(all->tab[0], "echo"))
	{
		if (ft_tablen(all->tab) == 1)
		{
			ft_putchar('\n');
			return ;
		}
		if (all->tab[1][0] == '-')
		{
			if (all->tab[1][1] == 'n')
				n = 1;
			else
				ft_putchar(all->tab[1][1]);
		}
		i = (n == 0 ? 1 : 2);
		while (all->tab[i])
		{
			ft_putstr(all->tab[i]);
			i++;
			if (all->tab[i])
				ft_putchar(' ');
		}
		if (n == 0)
			ft_putchar('\n');
	}
}
