/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:44:55 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 00:29:31 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	int	ind;

	ind = 0;
	while (data.environ[ind])
	{
		if (!ft_strncmp("PWD=", data.environ[ind], 4))
		break;
		ind++;
	}
	printf("%s\n", data.environ[ind] + 4);
}