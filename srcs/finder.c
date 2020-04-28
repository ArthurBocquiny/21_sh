/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:07:24 by arbocqui          #+#    #+#             */
/*   Updated: 2020/02/27 11:52:11 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**get_all_paths(char *path)
{
	char	**all_path;

	all_path = ft_strsplit(path, ':');
	return (all_path);
}

char	*get_right_path(char **all_path, char *binary)
{
	DIR				*files;
	struct dirent	*read;
	int				i;

	i = 0;
	if (!all_path)
		return (NULL);
	while (all_path[i])
	{
		if (!(files = opendir(all_path[i])))
			i++;
		else
		{
			while ((read = readdir(files)))
			{
				if (ft_strcmp(read->d_name, binary) == 0)
				{
					closedir(files);
					return (all_path[i]);
				}
			}
			closedir(files);
			i++;
		}
	}
	return (NULL);
}

char	*find_oldpwd(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D'
			&& env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D')
			return (env[i] + 7);
		i++;
	}
	return (NULL);
}

char	*find_home(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M'
			&& env[i][3] == 'E' && env[i][4] == '=')
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
			&& env[i][3] == 'H' && env[i][4] == '=')
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
