/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:52:16 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/06/21 17:40:53 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer)) + 1);
	if (!new)
		return (0);
	if (line)
	{
		while (line[i])
		{
			new[i] = line[i];
			i++;
		}
		free(line);
	}
	while (buffer[j])
	{
		new[i + j] = buffer[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src) + 1;
	dest = (char *)malloc(len * sizeof(char));
	if (!dest)
	{
		return (0);
	}
	dest = ft_memcpy(dest, src, len);
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}