/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:44:55 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 05:49:33 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	char			*pwd;
	struct s_list	*first;

	pwd = malloc(1);
	pwd[0] = '\0';
	first = data.t_environ;
	while (data.t_environ->next)
	{
		if (!ft_strncmp("PWD=", (char *)data.t_environ->content, 4))
			pwd = ft_strdup(data.t_environ->content);
		data.t_environ = data.t_environ->next;
	}
	if (!pwd)
		return ;
	printf("%s\n", pwd + 4);
	data.t_environ = first;
	free(pwd);
}