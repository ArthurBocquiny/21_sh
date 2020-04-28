/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:52:38 by arbocqui          #+#    #+#             */
/*   Updated: 2020/02/27 18:39:07 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	display_prompt(void)
{
	write(1, "csh-arbocqui$> ", 14);
}

void	display_line(char *line)
{
	ft_putstr(line);
	ft_putchar('\n');
}

int		display_command(char **av, char *right_path, char **env)
{
	pid_t	pid;
	char	*binary_path;
	char	*tmp;

	tmp = ft_strjoin(right_path, "/");
	binary_path = ft_strjoin(tmp, av[0]);
	pid = fork();
	if (pid < 0)
		exit(0);
	if (pid > 0)
		wait(0);
	if (pid == 0)
	{
		if (execve(binary_path, av, env) == -1 && execve(av[0], av, env) == -1)
			return(0);
	}
	ft_strdel(&binary_path);
	ft_strdel(&tmp);
	return (1);
}

void	display_echo(char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		ft_putstr(av[i]);
		if (av[i + 1])
			ft_putchar(' ');
		i++;
	}
}

void	display_table(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
	}
}

int		display_builtin(char **av, char ***env)
{
	if (ft_strcmp(av[0], "echo") == 0)
	{
		display_echo(av);
		ft_putchar('\n');
		return (1);
	}
	else if (ft_strcmp(av[0], "cd") == 0)
	{
		cd_para(av, env);
		return (1);
	}
	else if (ft_strcmp(av[0], "exit") == 0)
		exit(0);
	else if (ft_strcmp(av[0], "setenv") == 0)
	{
		if (len_tab(av) > 3)
		{
			ft_putstr("setenv: Too many arguments.\n");
			return(0);
		}
		if (!av[1])
			display_table(*env);
		else
			set_env(env, av[1], av[2]);
		return (1);
	}
	else if (ft_strcmp(av[0], "unsetenv") == 0)
	{
		if (!av[1])
		{
			ft_putstr("unsetenv: Too few arguments.\n");
			return (0);
		}
		unset_env(env, av);
		return (1);
	}
	else if (ft_strcmp(av[0], "env") == 0)
	{
		display_env(*env, av);
		return (1);
	}
	return (0);
}
