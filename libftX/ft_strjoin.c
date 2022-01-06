/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:56:41 by ael-hadd          #+#    #+#             */
/*   Updated: 2021/11/13 15:19:03 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = NULL;
	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (ptr);
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
