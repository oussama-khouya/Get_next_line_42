/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhouya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:40:59 by okhouya           #+#    #+#             */
/*   Updated: 2025/11/20 17:50:28 by okhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_till_newline(int fd, char *keeper)
{
	int		bytes;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	bytes = 1;
	while (!ft_strchr_gnl_bonus(keeper, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		keeper = ft_strjoin_gnl_bonus(keeper, buffer);
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
	line = ft_substr_gnl_bonus(keeper, 0, i);
	return (line);
}

static char	*update_keeper(char *keeper)
{
	int		i;
	int		len_ke;
	char	*new_keeper;

	len_ke = ft_strlen_gnl_bonus(keeper);
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
	new_keeper = ft_substr_gnl_bonus(keeper, i, len_ke - i);
	free(keeper);
	return (new_keeper);
}

char	*get_next_line_bonus(int fd)
{
	static char	*keeper[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	keeper[fd] = read_till_newline(fd, keeper[fd]);
	if (!keeper[fd])
		return (NULL);
	line = extract_line(keeper[fd]);
	keeper[fd] = update_keeper(keeper[fd]);
	return (line);
}
// #include <stdio.h>
// #include <fcntl.h>
// // int main()
// {
//     char *line;
//     int fd3 = open("test3.txt", O_RDWR);
//     int fd4 = open("test4.txt", O_RDWR);
//     int fd5 = open("test5.txt", O_RDWR);
//     line = get_next_line_bonus(fd3);
//     printf("%s", line);
//     free(line);
//     line = get_next_line_bonus(fd4);
//     printf("%s", line);
//     free(line);
//     line = get_next_line_bonus(fd5);
//     printf("%s", line);
//     free(line);
//     line = get_next_line_bonus(fd3);
//     printf("%s", line);
//     free(line);
//     line = get_next_line_bonus(fd3);
//     printf("%s", line);
//     free(line);    
// }
/*#include <stdio.h>
int	main()
{
	char *line3;
	char *line4;
	char *line5;

	int fd3 = open("test3.txt", O_RDWR);
    int fd4 = open("test4.txt", O_RDWR);
    int fd5 = open("test5.txt", O_RDWR);



	while (1)
	{
		line3 = get_next_line_bonus(fd3);
		line4 = get_next_line_bonus(fd4);
		line5 = get_next_line_bonus(fd5);
		if (!line3 && !line4 && !line5)
			break;
		if (line3)
		{
			printf("%s", line3);
			free(line3);
		}
		if (line4)
		{
			printf("%s", line4);
			free(line4);
		}
		if (line4)
		{
			printf("%s", line5);
			free(line5);
		}
	}
}*/