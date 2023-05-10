/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:41:50 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/10 21:21:12 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		is_equal(char *export)
{
	int	ind;

	ind = 0;
	while (export[ind])
	{
		if(export[ind] == '=')
			return (1);
		ind++;
	}
	return (0);
}

void	ft_export(void)
{
	char			*export;
	t_list			*first;
	
	first = data.t_mini;
	while (data.t_mini->next)
	{
		export = ft_strdup(data.t_mini->next->content);
		printf("%s\n", export);
		if (is_equal(export))
			ft_lstadd_back(&data.t_environ, ft_lstnew(export));
		data.t_mini = data.t_mini->next;
		free(export);
	}
	data.t_mini = first;
}
