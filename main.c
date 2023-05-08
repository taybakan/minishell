/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:20:03 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/09 00:08:29 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

int		main(void)
{
	int			ind;
	char		*input;
	char extern	**environ;

	ind = 0;
	while (environ[ind])
		ind++;
	data.environ = malloc(sizeof(char *) * (ind + 1));
	ind = 0;
	while (environ[ind])
	{
		data.environ[ind] = ft_strdup(environ[ind]);
		ind++;
	}
	data.environ[ind] = NULL;
	while (1)
	{
		input = readline("minishell_> ");
		add_history(input);
		get_input(input);
		check_input();
	}
	return (0);
}