/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:34:34 by vgarcia           #+#    #+#             */
/*   Updated: 2024/11/13 09:28:59 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

ssize_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		++i;
	}
	return (i);
}

ssize_t ft_size(void** obj)
{
    size_t i = 0;

    if (!obj)
    	return -1;
    while (obj[i])
    {
        i++;
    }
    return i;
}