/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 20:53:30 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/06 21:01:17 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/wait.h>

int			ft_exec(t_all *all, char **tab, char **env)
{
	pid_t	proces;
	char	*str;

	proces = fork();
	if (proces > 0)
		wait(NULL);
	if (proces == 0)
	{
		ft_exec2(all, tab, env, str);
	}
	return (1);
}

void		ft_exec2(t_all *all, char **tab, char **env, char *str)
{
	int		i;
	char	**path;
	int		exec;

	i = 0;
	exec = -1;
	if (ft_searchenv(all->env, "PATH"))
	{
		path = ft_strsplit(ft_searchenv(all->env, "PATH"), ':');
		while (path[i] && exec == -1)
		{
			str = ft_strjoin(path[i], "/");
			str = ft_strjoinfree(str, tab[0], 0);
			exec = execve(str, tab, env);
			free(str);
			i++;
		}
	}
	execve(tab[0], tab, env);
	ft_putstr("Minishell: command not found: ");
	ft_putendl(tab[0]);
	exit(0);
}
