/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:13:04 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 14:13:53 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_input(char *input)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(input, ' ');
	data.t_mini = ft_lstnew(split[0]);
	i++;
	while (split[i])
	{
		ft_lstadd_back(&data.t_mini, ft_lstnew(split[i]));
		i++;
	}
	return (0);
}

int		check_input()
{
	if (!ft_strncmp("env\0", data.t_mini->content, 4))
		ft_env();
	else if (!ft_strncmp("pwd\0", data.t_mini->content, 4))
		ft_pwd();
	else if (!ft_strncmp("exit\0", data.t_mini->content, 5))
		ft_exit();
	else if (!ft_strncmp("echo\0", data.t_mini->content, 5))
		ft_echo();
	else if (!ft_strncmp("export\0", data.t_mini->content, 7))
		ft_export();
	else if (!ft_strncmp("unset\0", data.t_mini->content, 6))
		ft_unset();
	else if (data.t_mini->content == NULL)
		return (1);
	else
		printf("Command Not Found: %s\n", data.t_mini->content);
	return (0);
}