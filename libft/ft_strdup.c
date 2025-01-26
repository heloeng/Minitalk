/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:16:15 by helde-so          #+#    #+#             */
/*   Updated: 2024/11/07 14:30:30 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*string_size;

	len = 0;
	while (s[len] != '\0')
	len++;
	string_size = (char *)malloc((len + 1) * sizeof(char));
	if (string_size == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string_size[i] = s[i];
		i++;
	}
	string_size[len] = '\0';
	return (string_size);
}
