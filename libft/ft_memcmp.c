/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:46:45 by helde-so          #+#    #+#             */
/*   Updated: 2024/11/07 17:29:29 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)

{
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;
	size_t			i;

	ptr_1 = (unsigned char *)s1;
	ptr_2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr_1[i] != ptr_2[i])
			return (ptr_1[i] - ptr_2[i]);
		i++;
	}
	return (0);
}
