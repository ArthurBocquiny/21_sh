/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:06:29 by arbocqui          #+#    #+#             */
/*   Updated: 2020/02/27 18:44:26 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	error_env(char *str)
{
	ft_putstr_fd("env : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" : No such file or directory\n", 2);
}

void	ft_error_cd(char *path)
{
	t_stat	file_stat;

	lstat(path, &file_stat);
	if (access(path, F_OK) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
	}
	else if (access(path, X_OK) == -1 && S_ISDIR(file_stat.st_mode))
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
	}
	else if (!S_ISDIR(file_stat.st_mode))
	{
		ft_putstr_fd("cd: not a directory: ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
	}
}

void	ft_error(char *builtin, char *path)
{

	if (ft_strcmp(builtin, "cd") == 0)
		ft_error_cd(path);
}
