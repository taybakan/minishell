/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 04:41:50 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 15:14:22 by taybakan         ###   ########.fr       */
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

	if (data.t_mini->next)
		export = ft_strdup(data.t_mini->next->content);
	else
		return ;
	printf("%s\n", export);
	if (!is_equal(export))
		return ;
	ft_lstadd_back(&data.t_environ, ft_lstnew(export));
	free(export);
}
