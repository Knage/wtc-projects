/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:09:51 by kcowle            #+#    #+#             */
/*   Updated: 2016/07/29 15:12:19 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char *s)
{
	size_t	start;
	size_t	end;
	char	*new;
	char *final;

	start = 0;
	end = ft_strlen(s);
	while (ft_iswhitespace(s[start]))
		start++;
	while (ft_iswhitespace(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	new = ft_strnew(end - start);
	if (new == NULL)
		return (NULL);
	final = ft_strncpy(new, s + start, end - start);
	free(s);
	return (final);
}
