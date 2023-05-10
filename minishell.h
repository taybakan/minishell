/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:20:14 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/10 21:22:22 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./lib/libft/libft.h"

struct	s_data
{
	t_list	*t_environ;
	t_list	*t_mini;
} data;	

int		get_input(char *input);
int		check_input(void);
void	ft_env(void);
void	ft_pwd(void);
void	ft_exit(void);
void	ft_echo(void);
int		ft_findenv(char *env);
int		ft_no_nl(char *str);
void	ft_export(void);
int		is_equal(char *export);
void	ft_unset(void);
void	ft_lstfree(void);
char	*check_access(char *cmd, char *all_path);
char	*check_env(char *s);
char	**get_arg(void);
int		ft_execve(void);
char	**get_env(void);
void	get_environ();

#endif