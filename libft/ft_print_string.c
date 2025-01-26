/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:55:41 by helde-so          #+#    #+#             */
/*   Updated: 2024/11/26 18:18:09 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_string(char *str)
{
	int	count;
	int	i;

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		count = count + ft_printchar(str[i]);
		i++;
	}
	return (count);
}
