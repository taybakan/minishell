/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:20:14 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 00:00:47 by taybakan         ###   ########.fr       */
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
	char			**environ;
	struct s_list	*t_mini;
} data;	

int		get_input(char *input);
int		check_input(void);
void	ft_env(void);
void	ft_pwd(void);
void	ft_exit(void);
void	ft_echo(void);

#endif