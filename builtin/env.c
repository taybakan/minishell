/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:05:10 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 00:06:22 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(void)
{
	int	ind;

	ind = 0;
	while (data.environ[ind])
	{
		printf("%s\n", data.environ[ind]);
		ind++;
	}
}