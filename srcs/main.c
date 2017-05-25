/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:46:00 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/18 19:12:02 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_initstruct(t_all *all)
{
	all->pwd = NULL;
	all->pastpwd = NULL;
	all->env = NULL;
	all->envcpy = NULL;
	all->tab = NULL;
}

void	ft_mainexec(t_all *all)
{
	ft_vartotab(all);
	if (ft_strcmp(all->tab[0], "echo") && ft_strcmp(all->tab[0], "cd") && \
		ft_strcmp(all->tab[0], "env") && ft_strcmp(all->tab[0], "exit") \
		&& ft_strcmp(all->tab[0], "setenv") \
		&& ft_strcmp(all->tab[0], "unsetenv"))
		ft_exec(all, &all->tab[0], all->env);
	else
	{
		ft_echoshell(all, 0, 0);
		ft_exitshell(all->tab);
		ft_cdshell(all);
		ft_envshell(all);
	}
}

char	*ft_tabtospace(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	return (line);
}

void	ft_main(t_all *all)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	ft_putprompt(all);
	while (get_next_line(0, &line) > 0)
	{
		if (line && line[0] != '\0')
		{
			line = ft_tabtospace(line);
			if (ft_checkonlyspace(line))
			{
				all->tab = ft_strsplit(line, ' ');
				ft_mainexec(all);
				ft_tabfree(all->tab);
			}
		}
		if (g_prompt == 0)
			ft_putprompt(all);
		else
			g_prompt = 0;
		ft_memdel((void**)&line);
	}
}

int		main(int argc, char **argv, char **env)
{
	t_all	*all;
	char	*line;
	int		i;

	i = 0;
	g_prompt = 0;
	while (env[i])
		i++;
	all = (t_all*)ft_memalloc(sizeof(t_all));
	ft_initstruct(all);
	all->env = ft_tabdup(env, i + 1);
	all->pwd = (char*)ft_memalloc(sizeof(char) * 4096);
	getwd(all->pwd);
	all->pastpwd = ft_strdup(all->pwd);
	signal(2, sigfunc);
	ft_main(all);
	return (1);
}
