/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:04:43 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 05:53:33 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_findenv(char *str)
{
	char	*env;
	struct s_list *first;

	first = data.t_environ;
	while (data.t_environ->next)
	{
		data.t_environ = data.t_environ->next;
		env = ft_strdup(data.t_environ->content);
		if (!ft_strncmp(str + 1, env, (ft_strlen(str) - 1)))
			printf("%s", env + ft_strlen(str));
	}
	data.t_environ = first;
	return (ft_strlen(str) - 1);
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
		return (1);
	}
	return (0);
}

void	ft_echo(void)
{
	char	*str;
	int		flag;
	int		i;

	flag = 0;
	if (data.t_mini->next)
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