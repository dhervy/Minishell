/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:33:23 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/18 18:47:07 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>

int					g_prompt;
typedef struct		s_all
{
	char			*pwd;
	char			*pastpwd;
	char			**env;
	char			**envcpy;
	char			**tab;
}					t_all;

void				ft_cdshell(t_all *all);
void				ft_exitshell(char **tab);
char				*ft_searchenv(char **env, char *str);
void				ft_envshell(t_all *all);
char				*ft_searchenv(char **env, char *str);
char				**ft_addenv(char **env, char *str, char *newstr);
char				**ft_removenv(char **env, char *str);
void				ft_echoshell(t_all *all, int n, int i);
void				ft_envshell2(t_all *all, int i, int j, int *arg);
int					ft_exec(t_all *all, char **tab, char **env);
int					ft_checkvar(char *str);
void				ft_cdshell2(t_all *all, char *str);
void				ft_exec2(t_all *all, char **tab, char **env, char *str);
void				ft_errorvar(void);
void				ft_initenvshell(t_all *all);
int					ft_env(t_all *all, int i);
void				ft_envi(t_all *all);
int					ft_envu(t_all *all, int i);
void				ft_vartotab(t_all *all);
void				ft_building(t_all *all);
void				ft_mainexec(t_all *all);
void				sigfunc(int sig);
char				**ft_envcopy(char **env, char *str);
char				**ft_envdelet(char **env, int sup);
int					ft_checkonlyspace(char *line);
void				ft_putprompt(t_all *all);

#endif
