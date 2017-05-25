/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:34:03 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/18 18:35:24 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_setenvshell(t_all *all)
{
	if (ft_tablen(all->tab) == 1)
		ft_puttabstr(all->env);
	else if (ft_tablen(all->tab) > 3)
		ft_putstr_fd("env: too many arguments\n", 2);
	else if (!ft_checkvar(all->tab[1]))
		ft_errorvar();
	else
		all->env = ft_addenv(all->env, all->tab[1], all->tab[2]);
}

void	ft_envshell(t_all *all)
{
	int		i;

	i = 1;
	if (!ft_strcmp(all->tab[0], "env"))
	{
		if (ft_tablen(all->tab) == 1)
			ft_puttabstr(all->env);
		else if (ft_tablen(all->tab) >= 2)
			ft_initenvshell(all);
	}
	else if (!ft_strcmp(all->tab[0], "setenv"))
		ft_setenvshell(all);
	else if (!ft_strcmp(all->tab[0], "unsetenv"))
	{
		if (ft_tablen(all->tab) == 1)
			ft_putendl_fd("unsetenv: Too few arguments.", 2);
		else
		{
			while (all->tab[i])
			{
				all->env = ft_removenv(all->env, all->tab[i]);
				i++;
			}
		}
	}
}

char	*ft_searchenv(char **env, char *str)
{
	int		i;
	int		j;

	i = 0;
	str = ft_strjoin(str, "=");
	j = ft_strlen(str);
	while (env[i])
	{
		if (ft_strnstr(env[i], str, ft_strlen(str)))
		{
			free(str);
			return (&env[i][j]);
		}
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_addenv(char **env, char *str, char *newstr)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	i = 0;
	tmp2 = ft_strjoin(str, "=");
	while (env[i])
	{
		if (ft_strnstr(env[i], tmp2, ft_strlen(tmp2)))
		{
			if (newstr)
				tmp = ft_strjoinfree(tmp2, newstr, 0);
			else
				tmp = ft_strdupfree(tmp2);
			free(env[i]);
			env[i] = ft_strdupfree(tmp);
			return (env);
		}
		i++;
	}
	tmp = (newstr ? ft_strjoinfree(tmp2, newstr, 0) : ft_strdupfree(tmp2));
	env = ft_envcopy(env, tmp);
	free(tmp);
	return (env);
}

char	**ft_removenv(char **env, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin(str, "=");
	while (env[i])
	{
		if (ft_strnstr(env[i], tmp, ft_strlen(tmp)))
		{
			env = ft_envdelet(env, i);
			free(tmp);
			return (env);
		}
		i++;
	}
	return (env);
}
