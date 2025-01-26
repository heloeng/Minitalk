/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:33:57 by helde-so          #+#    #+#             */
/*   Updated: 2024/11/07 19:36:28 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	str_len_1;
	size_t	str_len_2;
	size_t	total_str1_str2;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	str_len_1 = ft_strlen(s1);
	str_len_2 = ft_strlen(s2);
	total_str1_str2 = str_len_1 + str_len_2;
	new_str = (char *)malloc((total_str1_str2 + 1) * sizeof(char));
	if (!new_str)
	{
		return (NULL);
	}
	ft_strlcpy(new_str, s1, total_str1_str2 + 1);
	ft_strlcat(new_str, s2, total_str1_str2 + 1);
	return (new_str);
}
