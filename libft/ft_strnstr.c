/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkremer <dkremer@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:19:24 by dkremer           #+#    #+#             */
/*   Updated: 2023/10/23 23:46:29 by dkremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	unsigned int	h;
	unsigned int	n;

	h = 0;
	if (!*nee)
		return ((char *)hay);
	while (hay[h] && h < len)
	{
		n = 0;
		while (hay[h + n] == nee[n] && (h + n) < len && nee[n])
			n++;
		if (!nee[n])
			return ((char *)(hay + h));
		h++;
	}
	return (NULL);
}
