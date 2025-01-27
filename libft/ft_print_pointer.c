/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:02:52 by helde-so          #+#    #+#             */
/*   Updated: 2024/11/26 18:21:25 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointer(void *p)
{
	unsigned long	len;
	unsigned long	pnt;

	if (p == NULL)
	{
		ft_print_string("(nil)");
		return (5);
	}
	pnt = (unsigned long)p;
	ft_print_string("0x");
	len = ft_print_hexa_lower(pnt);
	return (len + 2);
}
