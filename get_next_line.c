/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:02:41 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/06/21 15:56:52 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_stash(char **stash)
{
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

char	*get_line(char *stash)
{
	char	*printed_line;
	int		len;

	len = 0;
	if (!stash)
		return (0);
	while (stash[len] != '\n')
		len++;
	printed_line = (char *)malloc(len + 2);
	if (!printed_line)
		return (0);
	len = 0;
	while (stash[len] != '\n' && stash[len])
	{
		printed_line[len] = stash[len];
		len++;
	}
	if (stash[len] == '\n')
	{
		printed_line[len] = '\n';
		printed_line[len + 1] = '\0';
	}
	else
		printed_line[len] = '\0';
	return (printed_line);
}

char	*clean_remaining(char *stash)
{
	char	*remaining_text;
	int		i;
	int		j;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (0);
	remaining_text = (char *)malloc(ft_strlen(stash) - i + 1);
	if (!remaining_text)
		return (0);
	j = 0;
	while (stash[i])
	{
		remaining_text[j] = stash[i + 1];
		i++;
		j++;
	}
	remaining_text[j] = '\0';
	free(stash);
	return (remaining_text);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (0);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*printed_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	printed_line = get_line(stash);
	stash = clean_remaining(stash);
	return (printed_line);
}

int main() 
{
    int fd;
    int i;
    char *next_line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0) 
    {
        printf("Failed to open the file.\n");
        return (1);
    }
	i = 1;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	next_line = get_next_line(fd);
    printf("Read line_%d: %s \n", i, next_line);
	i++;
	
	/*
    i = 0;
	while (i < 30) 
    {
        i++;
		next_line = get_next_line(fd);
        printf("Read line_%d: %s \n", i, next_line);
    }
	*/
    if(next_line)
        free(next_line);
    close (fd);
    return (0);
}
