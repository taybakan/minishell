/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:41:50 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 06:07:42 by taybakan         ###   ########.fr       */
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
	struct s_list	*first;

	export = ft_strdup(data.t_mini->next->content);
	if (!is_equal(export))
		return ;
	first = data.t_environ;
	while(data.t_environ->next)
		data.t_environ = data.t_environ->next;
	ft_lstadd_back(&data.t_environ, ft_lstnew(export));
	data.t_environ = first;
}
