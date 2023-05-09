/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:05:10 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 05:50:41 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(void)
{
	struct s_list	*first;
	
	first = data.t_environ;
	while (data.t_environ->next)
	{
		data.t_environ = data.t_environ->next;
		printf("%s\n", data.t_environ->content);
	}
	data.t_environ = first;
}