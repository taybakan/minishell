/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:49:03 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 14:03:33 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstfree(void)
{
	t_list	*first;

	first = data.t_mini;
	while (data.t_mini->next)
	{
		while (data.t_mini->next->next)
			data.t_mini = data.t_mini->next;
		free(data.t_mini->next->content);
		data.t_mini->next = NULL;
		data.t_mini = first;
	}
	free(data.t_mini->content);
}