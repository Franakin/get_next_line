/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 15:11:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/15 16:29:17 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*check_error(char *static_save, int b_read)
{
	if (!*static_save || b_read < 0)
	{
		free(static_save);
		static_save = NULL;
	}
	return (static_save);
}

char	*get_next_line(int fd)
{
	static char	*static_save = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			b_read;

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (!static_save)
	{
		static_save = (char *)malloc(sizeof(char));
		if (!static_save)
			return (NULL);
		*static_save = '\0';
	}
	b_read = 1;
	while (!nl_position(static_save) && b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';
		static_save = make_save(static_save, buffer);
	}
	static_save = check_error(static_save, b_read);
	ret = make_line(static_save);
	static_save = to_next_line(static_save);
	return (ret);
}
