/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:45:55 by helde-so          #+#    #+#             */
/*   Updated: 2024/11/07 15:57:30 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	str_len;

	str_len = (size_t)ft_strlen(s);
	if (start > str_len)
	{
		return (ft_strdup(&s[str_len]));
	}
	if (len > (str_len - start))
	{
		len = str_len - start;
	}
	substr = (char *)malloc(len +1);
	if (!substr)
		return (NULL);
	i = start;
	j = 0;
	while (i < str_len && j < len)
	substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}
