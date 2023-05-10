/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 05:03:27 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/10 21:59:10 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(void)
{
	t_list	*first;
	t_list	*mf;
	int		flag;

	flag = 0;
	mf = data.t_mini;
	first = data.t_environ;
	while (data.t_mini->next)
	{
		data.t_mini = data.t_mini->next;
		while (data.t_environ->next)
		{
			if (data.t_environ->next && (!ft_strncmp(data.t_mini->content, data.t_environ->next->content, ft_strlen(data.t_mini->content))) && (((char *)(data.t_environ->next->content))[ft_strlen(data.t_mini->content)] == '='))
			{					
				if (data.t_environ->next->next)
					data.t_environ->next = data.t_environ->next->next;
				else
					data.t_environ->next = NULL;
				flag = 1;
			}
			if (data.t_environ->next)
				data.t_environ = data.t_environ->next;
			if (!data.t_environ->next && !flag)
				printf("minishell: unset: '%s': not a valid identifier\n", data.t_mini->content);
		}
	}
	data.t_mini = mf;
	data.t_environ = first;
}