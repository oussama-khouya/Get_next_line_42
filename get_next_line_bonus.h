/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhouya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:56:16 by okhouya           #+#    #+#             */
/*   Updated: 2025/11/20 17:56:35 by okhouya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line_bonus(int fd);
char	*ft_strjoin_gnl_bonus(char *s1, char *s2);
char	*ft_strchr_gnl_bonus(char *s, int c);
char	*ft_substr_gnl_bonus(char *s, int start, int len);
int		ft_strlen_gnl_bonus(char *s);

#endif
