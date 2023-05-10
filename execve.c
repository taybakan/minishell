/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:14:56 by taybakan          #+#    #+#             */
/*   Updated: 2023/05/10 20:05:56 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_access(char *cmd, char *all_path)
{
	int		i;
	char	**path;
	
	path = ft_split(all_path, ':');
	path[0] = ft_strdup(path[0] + 4);
	i = 0;
	while(path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	i = 0;
	while(path[i])
	{
		path[i] = ft_strjoin(path[i], cmd);
		i++;
	}
	i = 0;
	while(path[i])
	{
		if(access(path[i], F_OK) == 0)
			break;
		i++;
	}
	if (path[i] == NULL)
		return(NULL);
	return(path[i]);
}

char	*check_env(char *s)
{
	size_t	i;
	char	*env;
	t_list	*first;

	first = data.t_environ;
	while(data.t_environ->next)
	{
		env = ft_strdup(data.t_environ->content);
		i = 0;
		while(i < ft_strlen(s))
		{
			while(s[i] == env[i])
			{
				if (i == (ft_strlen(s) - 1))
				{
					data.t_environ = first;
					return (env);
				}
				i++;
			}
			i++;
		}
		data.t_environ = data.t_environ->next;
	}
	data.t_environ = first;
	return (NULL);
}

char	**get_arg(void)
{
	int		i;
	char	**arg;
	t_list	*first;
	
	i = 0;
	first = data.t_mini;
	while (data.t_mini->next)
	{
		data.t_mini = data.t_mini->next;
		i++;
	}
	arg = malloc(sizeof(char *) * (i + 1));
	data.t_mini = first;
	i = 0;
	while (data.t_mini->next)
	{
		arg[i] = ft_strdup(data.t_mini->content);
		data.t_mini = data.t_mini->next;
		i++;
	}
	arg[i] = ft_strdup(data.t_mini->content);
	arg[i + 1] = NULL;
	data.t_mini = first;
	return (arg);
}

char	**get_env(void)
{
	int		i;
	char	**env;
	t_list	*first;
	
	i = 0;
	first = data.t_environ;
	while (data.t_environ->next)
	{
		data.t_environ = data.t_environ->next;
		i++;
	}
	env = malloc(sizeof(char *) * (i + 1));
	data.t_environ = first;
	i = 0;
	while (data.t_environ->next)
	{
		env[i] = ft_strdup(data.t_environ->content);
		data.t_environ = data.t_environ->next;
		i++;
	}
	env[i] = ft_strdup(data.t_environ->content);
	env[i + 1] = NULL;
	data.t_environ = first;
	return (env);
}

int		ft_execve(void)
{
	int		pid;
	char	**env;
	char	**arg;
	char	*path;
	char	*pwc;
	char	*cmd;
	t_list	*first;

	first = data.t_mini;
	cmd = ft_strdup(data.t_mini->content);
	path = check_env("PATH");
	if (!path)
		return(printf("Path not found!\n"));
	pwc = check_access(cmd, path);
	if (!pwc)
		return(printf("Command not found!\n"));
	env = get_env();
	arg = get_arg();
	data.t_mini = first;
	pid = fork();
	if(pid == 0)
		execve(pwc, arg, env);
	else
		waitpid(pid, NULL, 0);
	return (0);
}