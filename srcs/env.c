/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:56:34 by arbocqui          #+#    #+#             */
/*   Updated: 2020/02/27 18:34:53 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		check_var_exist(char **env, char *var_name)
{
	int		i;
	int		j;
	int		diff;

	i = -1;
	j = 0;
	diff = 0;
	while (env[++i])
	{
		while (env[i][j] != '=' && var_name[j])
		{
			if (env[i][j] != var_name[j])
				diff++;
			j++;
		}
		if (diff == 0 && !var_name[j] && env[i][j] == '=')
			return (i);
		j = 0;
		diff = 0;
	}
	return (-1);
}

int		check_var_alpha(char *var)
{
	int		i;

	i = -1;
	while (var[++i])
	{
		if (ft_isalpha(var[i]) == 0)
			return (0);
	}
	return (1);
}

void	create_new_var(char ***env, char *av1, char *av2)
{
	char	**env_cpy;
	int		i;
	char	*var;
	char	*tmp;

	i = 0;
	env_cpy = cpy_env(*env, 1);
	var = NULL;
	if (av1 && check_var_alpha(av1))
		tmp = ft_strjoin(av1, "=");
	else
	{
		ft_putstr("setenv: Must only contains alphanumeric characters.\n");
		ft_free_tab(env_cpy);
		return ;
	}
	if (av2)
		var = ft_strjoin(tmp, av2);
	else
		var = ft_strdup(tmp);
	ft_strdel(&tmp);
	while (env_cpy[i])
		i++;
	env_cpy[i++] = ft_strdup(var);
	free(var);
	env_cpy[i] = 0;
	ft_free_tab(*env);
	*env = env_cpy;
}

void	change_var(char ***env, char *av1, char *av2)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	**env_cpy;
	
	i = check_var_exist(*env, av1);
	tmp2 = ft_strjoin(av1, "=");
	if (av2)
		tmp = ft_strjoin(tmp2, av2);
	else
		tmp = ft_strdup(tmp2);
	ft_strdel(&tmp2);
	env_cpy = cpy_env(*env, 0);
	ft_strdel(&env_cpy[i]);
	env_cpy[i] = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_free_tab(*env);
	*env = env_cpy;
}

void	set_env(char ***env, char *av1, char *av2)
{
	if (check_var_exist(*env, av1) == -1)
		create_new_var(env, av1, av2);
	else
		change_var(env, av1, av2);
}

int		not_cpy(char *var, char **av)
{
	int		i;

	i = 0;
	while (av[++i])
	{
		if (ft_strcmp(var, av[i]) == 0)
			return (0);
	}
	return (1);
}

int		nb_real_var(char **env, char **av)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (av[++i])
	{
		if (check_var_exist(env, av[i]) != -1)
			nb++;
	}
	return (nb);
}

void	unset_env(char ***env, char **av)
{
	char	**tab;
	int		i;
	char	**env_cpy;
	int		j;
	char	**split;

	split = NULL;
	tab = NULL;
	env_cpy = cpy_env(*env, 0);
	i = len_tab(env_cpy) - nb_real_var(*env, av);
	if (!(tab = (char**)malloc(sizeof(char*) * (i + 1))))
		return ;
	i = 0;
	j = 0;
	while (env_cpy[i])
	{
		split = ft_strsplit(env_cpy[i], '=');
		if (not_cpy(split[0], av) != 0)
			tab[j++] = ft_strdup(env_cpy[i]);
		i++;
		ft_free_tab(split);
	}
	tab[j] = 0;
	ft_free_tab(*env);
	ft_free_tab(env_cpy);
	*env = tab;
}
