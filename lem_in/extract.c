/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:11:16 by knage             #+#    #+#             */
/*   Updated: 2016/07/07 16:54:34 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    add_room(t_data *curr)
{
    t_data *head;
    
    if (curr == NULL)
        head = NULL;
    else
        head = curr;
    curr = (t_data *)malloc(sizeof(t_data));
    curr->next  = head;
    head = curr;
    curr = head;
}

void	get_ant_numbers(t_env *env)
{
    char	*line;
    long	ant_numbers;
    
    get_next_line(0, &line);
    ant_numbers = ft_atoil(line);
    if (ant_numbers != 0)
        env->ant_count = ant_numbers;
    else
    {
        ft_putstr("error: invalid input for number of ants");
        exit(0);
    }
}

void	get_room(char *str, t_data *room)
{
    int i;

    i = 0;
	if (is_valid_room(str))
	{
        add_room(room);
        room->name = build_str(str, i, ' ');
   //     room->x = ft_atoi(build_str(str, i, ' '));
 //       room->y = ft_atoi(build_str(str, i, ' '));
	}
    else
    {
        ft_putstr("error: invalid room");
        exit(0);
    }
}

void	get_link(char *str, t_data *room)
{
    if (room)
        ft_putstr(str);
}

int    check_special(char *line, int type)
{
    if (type != 0)
    {
        ft_putstr("error: no cords entered");
        exit(0);
    }
    if (ft_strcmp(line, "##start") == 0)
        return (1);
    else if (ft_strcmp(line, "##end") == 0)
        return (1);
    else
    {
        ft_putstr("error: please use ##start or ##end");
        exit(0);
        return (2);
    }
}
