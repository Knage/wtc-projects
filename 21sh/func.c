/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:59:48 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/11 10:30:09 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	ft_getenv(t_env *env, char *text)
{
	int				i;

	i = 0;
	text++;
	while (env->enviro[i] != NULL)
	{
		if (ft_strncmp(text, env->enviro[i], ft_strlen(text)) == 0)
		{
			ft_putstr(env->enviro[i]);
			ft_putstr("\n");
		}
		i++;
	}
}

int		ft_pow(int n, int p)
{
	int		result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

void	ft_echo(t_env *env, char *line)
{
	t_echo	ec;

	init_echo(line, &ec);
	if (ec.e == 1)
	{
		ft_putstr(line);
		if (ec.newline == 0)
			ft_putchar('\n');
		return ;
	}
	if (line[0] == '$')
	{
		ft_getenv(env, line);
		ec.state = 0;
	}
	ec.i = 0;
	ft_handle3(&ec, line);
}

char	*get_path(t_env *env)
{
	int			i;
	char		*tmp;
	extern char	**environ;

	i = 0;
	while (1)
	{
		if (ft_strncmp(env->enviro[i], "PATH", 3) == 0)
		{
			tmp = (char *)malloc(sizeof(char *) * ft_strlen(env->enviro[i]));
			ft_strcpy(tmp, env->enviro[i]);
			break ;
		}
		i++;
	}
	tmp[ft_strlen(tmp) + 1] = '\0';
	return (tmp);
}
