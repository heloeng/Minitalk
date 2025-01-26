/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:58:17 by helde-so          #+#    #+#             */
/*   Updated: 2024/12/02 17:22:27 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexa_lower(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_hexa_lower(n / 16);
	ft_printchar("0123456789abcdef"[n % 16]);
	return (count + 1);
}
