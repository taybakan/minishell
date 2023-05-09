/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:20:03 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 05:37:31 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

void	get_environ(void)
{
	int			ind;
	char extern	**environ;

	ind = 0;
	data.t_environ = ft_lstnew(environ[0]);
	while (environ[ind])
	{
		ft_lstadd_back(&data.t_environ, ft_lstnew(environ[ind]));
		ind++;
	}
}


int		main(void)
{
	char		*input;

	get_environ();
	while (1)
	{
		input = readline("minishell_> ");
		add_history(input);
		get_input(input);
		check_input();
	}
	return (0);
}