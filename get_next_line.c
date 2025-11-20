/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhouya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:08:11 by okhouya           #+#    #+#             */
/*   Updated: 2025/11/17 21:18:16 by okhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_till_newline(int fd, char *keeper)
{
	int		bytes;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	bytes = 1;
	while (!ft_strchr_gnl(keeper, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		keeper = ft_strjoin_gnl(keeper, buffer);
	}
	free(buffer);
	return (keeper);
}

static char	*extract_line(char *keeper)
{
	int		i;
	char	*line;

	i = 0;
	while (keeper[i] && keeper[i] != '\n')
		i++;
	if (keeper[i] == '\n')
		i++;
	line = ft_substr_gnl(keeper, 0, i);
	return (line);
}

static char	*update_keeper(char *keeper)
{
	int		i;
	char	*new_keeper;

	i = 0;
	while (keeper[i] && keeper[i] != '\n')
		i++;
	if (!keeper[i])
	{
		free(keeper);
		return (NULL);
	}
	if (keeper[i] == '\n')
		i++;
	new_keeper = ft_substr_gnl(keeper, i, ft_strlen_gnl(keeper) - i);
	free(keeper);
	return (new_keeper);
}

char	*get_next_line(int fd)
{
	char static	*keeper;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keeper = read_till_newline(fd, keeper);
	if (!keeper)
		return (NULL);
	line = extract_line(keeper);
	keeper = update_keeper(keeper);
	return (line);
}
// #include <fcntl.h>
// #include <stdio.h>
// int	main()
// {
// // 	int	fd;
// // 	// char *keeper = NULL;
// // 	// char *result;
//  	char *line;
// // 	// char *new_keeper;

// // 	fd = open("test.txt", O_RDONLY);
// // 	// result = read_till_newline(fd,keeper);
// // 	// line = extract_line(result);
// // 	// new_keeper = update_keeper(result);

// int fd3 = open("test3.txt", O_RDWR);
// int fd4 = open("test4.txt", O_RDWR);
// int fd5 = open("test5.txt", O_RDWR);

// line = get_next_line(fd3);
// printf("%s", line);

// line = get_next_line(fd4);
// printf("%s", line);

// line = get_next_line(fd3);
// printf("%s", line);

// }