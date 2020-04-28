/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:16:34 by arbocqui          #+#    #+#             */
/*   Updated: 2020/02/27 18:35:34 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*read_line(void)
{
	char	*res;

	res = NULL;
	get_next_line(0, &res);
	return (res);
}

static int		ft_strschr(char *s, char c)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_stock_flags(int *flags, char *options)
{
	int			i;
	int			j;

	j = 1;
	i = 0;
	while (options[j])
	{
		if ((i = ft_strschr("LP", options[j])) == -1)
		{
			ft_putstr("cd: cd [ -P | -L ] [ args ].\n");
			return (-1);
		}
		*flags |= (1 << i);
		j++;
	}
	return (0);
}

int				ft_parsing(int ac, char **f_names, int *flags)
{
	int			i;

	i = 0;
	while (++i < ac && f_names[i][0] == '-' && f_names[i][1])
	{
		if (ft_stock_flags(flags, f_names[i]) == -1)
			return (-1);
	}
	return (i);
}

void	change_dir(char *path, char ****env, char *new_oldpwd)
{
	char	*new_pwd;

	new_pwd = NULL;
	if (chdir(path) == -1)
		ft_error("cd", path);
	set_env(*env, "OLDPWD", new_oldpwd);
	new_pwd = getcwd(NULL, 0);
	set_env(*env, "PWD", new_pwd);
	ft_strdel(&new_pwd);
}

void	cd_para(char **av, char ***env)
{
	int		i;
	int		flags;
	char	*new_oldpwd;

	i = 0;
	new_oldpwd = getcwd(NULL, 0);
	if ((i = ft_parsing(len_tab(av), av, &flags)) == -1)
	{
		ft_strdel(&new_oldpwd);
		return ;
	}
	if (!av[1])
		change_dir(find_home(*env), &env, new_oldpwd);
	else if (av[i] && ft_strcmp(av[i], "-") == 0)
		change_dir(find_oldpwd(*env), &env, new_oldpwd);
	else if (av[i])
		change_dir(av[i], &env, new_oldpwd);
	else
		change_dir(find_home(*env), &env, new_oldpwd);
	ft_strdel(&new_oldpwd);
}
