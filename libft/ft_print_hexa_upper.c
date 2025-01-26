/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:01:59 by helde-so          #+#    #+#             */
/*   Updated: 2024/12/02 18:30:49 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexa_upper(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_hexa_upper(n / 16);
	ft_printchar("0123456789ABCDEF"[n % 16]);
	return (count + 1);
}
