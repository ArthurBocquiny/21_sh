/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:05:57 by arbocqui          #+#    #+#             */
/*   Updated: 2020/02/27 18:35:00 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		len_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**add_var_env(char *av, char **env_cpy)
{
	int		i;
	char	**new_env;

	i = 0;
	new_env = NULL;
	if (!(new_env = (char**)malloc(sizeof(char*) * (len_tab(env_cpy) + 2))))
		return (NULL);
	while (env_cpy[i])
	{
		new_env[i] = ft_strdup(env_cpy[i]);
		i++;
	}
	ft_free_tab(env_cpy);
	new_env[i++] = ft_strdup(av);
	new_env[i] = 0;
	return (new_env);
}

char	**create_exec(char **av, int index)
{
	char	**exec;
	int		i;
	int		len;

	exec = NULL;
	i = index - 1;
	len = 0;
	while (av[++i])
		len++;
	if (!(exec = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	i = index;
	len = 0;
	while (av[i])
	{
		exec[len] = ft_strdup(av[i]);
		len++;
		i++;
	}
	exec[len] = 0;
	return (exec);
}

void		exec_env(char **av, int index, char **env_cpy, char **env)
{
	char	**all_path;
	char	*right_path;
	char	**exec_arg;

	exec_arg = NULL;
	all_path = get_all_paths(find_path(env));
	right_path = get_right_path(all_path, av[index]);
	exec_arg = create_exec(av, index);
	if (display_command(exec_arg, right_path, env_cpy) == 0)
	{
		ft_putstr(exec_arg[0]);
		ft_putstr(": command not found\n");
		exit(0);
	}
	ft_free_tab(all_path);
	ft_free_tab(exec_arg);
}

void	display_env(char **env, char **av)
{
	int		i;
	char	**env_cpy;
	int		j;
   int             nb_ex;

    nb_ex = 0;
	i = 1;
	j = -1;
	env_cpy = cpy_env(env, 0);
	if (ft_strcmp(av[0], "env") == 0 && !av[1])
		display_table(env_cpy);
	else
	{
		while (av[i])
		{
			if (i == 1
			&& ((av[i][0] == '-' && !av[i][1]) || ft_strcmp(av[i], "-i") == 0))
			{
				while (env_cpy[++j])
					ft_strdel(&env_cpy[j]);
			}
			else if (ft_strchr(av[i], '=') != 0)
				env_cpy = add_var_env(av[i], env_cpy);
			else
			{
				exec_env(av, i, env_cpy, env);
				nb_ex++;
				while (av[i + 1])
					i++;
			}
			i++;
		}
		if (nb_ex == 0)
			display_table(env_cpy);
	}
	ft_free_tab(env_cpy);
}

char	**cpy_env(char **env, int nb)
{
	char	**tab;
	int		i;

	tab = NULL;
	i = 0;
	while (env[i])
		i++;
	if (!(tab = (char**)malloc(sizeof(char*) * (i + 1 + nb))))
		return (NULL);
	i = 0;
	while (env[i])
	{
		tab[i] = ft_strdup(env[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
