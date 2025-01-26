/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:48:45 by helde-so          #+#    #+#             */
/*   Updated: 2024/12/02 18:38:02 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (c == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_print_dec_int(va_arg(args, int));
	else if (c == 'u')
		count += ft_print_dec_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_print_hexa_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_print_hexa_upper(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_printchar('%');
	else if (c == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	int		i;

	count = 0;
	i = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_formats(str[i], args);
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
