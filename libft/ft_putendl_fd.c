/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:50:06 by helde-so          #+#    #+#             */
/*   Updated: 2024/11/07 11:54:14 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char		*ptr;

	ptr = s;
	if (fd < 0 || s == NULL)
		return ;
	while (*ptr != '\0')
	{
		write(fd, ptr, 1);
		ptr++;
	}
	write(fd, "\n", 1);
}
