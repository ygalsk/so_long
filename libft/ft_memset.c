/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:28:36 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/27 02:29:24 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	bvalue;

	bvalue = (unsigned char)value;
	p = (unsigned char *) ptr;
	while (num > 0)
	{
		*p = bvalue;
		p++;
		num--;
	}
	return (ptr);
}
