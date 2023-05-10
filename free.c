/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:49:03 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/10 20:29:56 by taybakan         ###   ########.fr       */
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

void	ft_envfree(void)
{
	t_list	*first;

	first = data.t_environ;
	while (data.t_environ->next)
	{
		while (data.t_environ->next->next)
			data.t_environ = data.t_environ->next;
		printf("%s\n", data.t_environ->content);
		free(data.t_environ->next->content);
		data.t_environ->next = NULL;
		data.t_environ = first;
	}
	free(data.t_environ->content);
}