/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:22:05 by arbocqui          #+#    #+#             */
/*   Updated: 2020/02/27 19:42:29 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*cpy_exceptfirst(char *arg)
{
	char	*new;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(arg)))))
		return (NULL);
	while (arg[i])
	{
		new[j] = arg[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

int		check_varenv(char *var, char *tmp)
{
	int		i;

	i = -1;
	while (var[++i] != '=' && var[i])
	{
		if (var[i] != tmp[i])
			return (0);
	}
	return (1);
}

char	*cpy_valuevar(char **env, char *tmp)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	new = NULL;
	while (env[++i])
	{
		if (check_varenv(env[i], tmp) == 1)
		{
			if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(env[i]) - (ft_strlen(tmp))))))
				return (NULL);
			while (env[i][k] != '=')
				k++;
			k++;
			while (env[i][k])
			{
				new[j] = env[i][k];
				j++;
				k++;
			}
			new[j] = '\0';
			return (new);
		}
	}
	return (new);
}

char	*transform_line(char *line)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(line) + 1))))
		return (NULL);
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == '"')
			new[i] = ' ';
		else
			new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**parse_line(char *line, char **env)
{
	char 	**new_arg;
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	i = -1;
	line = transform_line(line);
	new_arg = ft_strsplit(line, ' ');
	ft_strdel(&line);
	while (new_arg[++i])
	{
		if (new_arg[i][0] == '~' && !new_arg[i][1])
		{
			ft_strdel(&new_arg[i]);
			new_arg[i] = ft_strdup(find_home(env));
		}
		else if (new_arg[i][0] == '~' && new_arg[i][1])
		{
			tmp = cpy_exceptfirst(new_arg[i]);
			ft_strdel(&new_arg[i]);
			new_arg[i] = ft_strjoin("/home/", tmp);
		}
		else if (new_arg[i][0] == '$' && new_arg[i][1])
		{
			tmp2 = cpy_exceptfirst(new_arg[i]);
			ft_strdel(&new_arg[i]);
			tmp = cpy_valuevar(env, tmp2);
			if (tmp != NULL)
				new_arg[i] = ft_strdup(tmp);
			else
			{
				ft_putstr(tmp2);
				ft_putstr(": Undefined variable.\n");
				ft_strdel(&tmp2);
				ft_free_tab(new_arg);
				return (NULL);
			}
			ft_strdel(&tmp2);
			ft_strdel(&tmp);
		}
	}
	return (new_arg);
}

int		not_a_builtin(char **av)
{
	if (ft_strcmp(av[0], "cd") == 0 || ft_strcmp(av[0], "env") == 0
	|| ft_strcmp(av[0], "setenv") == 0 || ft_strcmp(av[0], "unsetenv") == 0
	|| ft_strcmp(av[0], "echo") == 0 || ft_strcmp(av[0], "exit") == 0)
			return (0);
	return (1);
}

void	loop(char **env)
{
	char	*line;
	char	**av;
	char	**all_path;
	char	*right_path;

	right_path = NULL;
	av = NULL;
	line = NULL;
	while (1)
	{
		all_path = get_all_paths(find_path(env));
		display_prompt();
		line = read_line();
		av = parse_line(line, env);
		if (av[0])
		{
			right_path = get_right_path(all_path, av[0]);
			if (display_builtin(av, &env) == 1)
				ft_putstr("");
			else if (not_a_builtin(av) == 1
			&& display_command(av, right_path, env) == 0)
			{
				ft_putstr(av[0]);
				ft_putstr(": command not found\n");
				exit(0);
			}
		}
		ft_strdel(&line);
		(av) ? ft_free_tab(av) : 0;
		(all_path) ? ft_free_tab(all_path) : 0;
	}
}


int		main(int ac, char **av, char **env)
{
	char	**env_cpy;

	env_cpy = NULL;
	if (ac < 0 || !av)
		return (0);
	env_cpy = cpy_env(env, 0);
	loop(env_cpy);
	return (0);
}
