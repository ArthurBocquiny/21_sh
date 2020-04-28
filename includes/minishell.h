/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:23:32 by arbocqui          #+#    #+#             */
/*   Updated: 2020/02/27 13:28:31 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

# include "../libft/libft.h"

typedef struct dirent		t_dirent;
typedef struct stat			t_stat;

# define CD_L				1
# define CD_P				2

char						**get_all_paths(char *path);
char						*find_path(char **env);
char						*get_right_path(char **all_path, char *binary);

char						*read_line(void);

void						display_table(char **tab);
void						display_prompt(void);
void						display_line(char *line);
int							display_command(char **av, char *right_path, char
							**env);
int							display_builtin(char **av, char ***env);
void						cd_para(char **av, char ***env);

char						**cpy_env(char **env, int nb);
void						set_env(char ***env, char *av1, char *av2);
void						unset_env(char ***env, char **av);
void						display_env(char **env, char **av);
int							len_tab(char **tab);

char						*find_home(char **env);
char						*find_path(char **env);
char						*find_oldpwd(char **env);

void						ft_error(char *builtin, char *path);
void						ft_error_cd(char *path);
void						error_env(char *str);

#endif
