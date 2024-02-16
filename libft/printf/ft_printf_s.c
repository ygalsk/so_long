/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:23:40 by dkremer           #+#    #+#             */
/*   Updated: 2024/02/16 15:34:08 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_printf_s(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
	{
		i = write(1, "(null)", 6);
		if (i < 0)
			return (-1);
		return (i);
	}
	while (*str)
	{
		ft_printf_char(*str);
		str++;
		i++;
	}
	return (i);
}
