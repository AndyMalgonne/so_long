/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:37:09 by amalgonn          #+#    #+#             */
/*   Updated: 2024/02/07 10:41:18 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnjoin(char *s1, char const *s2, size_t new_line)
{
	char		*str;
	size_t		i;
	size_t		j;

	str = (char *)malloc(ft_strlen(s1) + new_line + 1);
	if (!s1 || !s2 ||!(str))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < new_line)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
