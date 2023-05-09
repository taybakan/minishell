/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 05:03:27 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 12:25:54 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(void)
{
	struct s_list	*first;

	first = data.t_environ;
	while(data.t_environ->next)
	{
		if(data.t_environ->next)
		{	
			if (!ft_strncmp(data.t_mini->next->content, data.t_environ->next->content, ft_strlen(data.t_mini->next->content)))
			{
				if (data.t_environ->next->next)
					data.t_environ->next = data.t_environ->next->next;
				else
					data.t_environ->next = NULL;
			}
		}
		if (data.t_environ->next)
			data.t_environ = data.t_environ->next;
	}
	data.t_environ = first;
}