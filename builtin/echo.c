/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:04:43 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 01:47:55 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_findenv(char *env)
{
	int	ind;

	ind = 0;
	while (data.environ[ind])
	{
		if (!ft_strncmp(env + 1, data.environ[ind], (ft_strlen(env) - 1)))
			printf("%s", data.environ[ind] + ft_strlen(env));
		ind++;
	}
	return (ft_strlen(env) - 1);
}

int		ft_no_nl(char *str)
{
	int	i;
	
	if (!str)
		return (0);
	if (!ft_strncmp("-n", str, 2))
	{
		i = 1;
		while (str[i] != '\0')
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_echo(void)
{
	char	*str;
	int		flag;
	int		i;

	flag = ft_no_nl(data.t_mini->next->content);
	if (flag && data.t_mini->next)
		data.t_mini = data.t_mini->next;
	while (data.t_mini->next)
	{
		data.t_mini = data.t_mini->next;
		str = ft_strdup(data.t_mini->content);
		i = 0;
		while (str[i])
		{
			if (str[i] == '$')
				i += ft_findenv(str + i);
			else
				printf("%c", str[i]);
			i++;
		}
		free(str);
		if (data.t_mini->next)
			printf(" ");
	}
	if (!flag)
		printf("\n");
}