#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*to_next_line(char *old_save)
{
	char	*new_save;
	int		i;
	int		k;

	k = 0;
	while (old_save[k] && old_save[k] != '\n')
		k++;
	if (old_save[k] == '\n')
		k++;
	new_save = (char *)malloc(sizeof(char) * (s_len(&old_save[k]) + 1));
	if (!new_save)
		return (NULL);
	i = 0;
	while (old_save[k])
	{
		new_save[i] = old_save[k];
		i++;
		k++;
	}
	new_save[i] = '\0';
	free(old_save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*static_save = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			b_read;

	b_read = 1;
	if (!static_save)
	{
		static_save = (char *)malloc(sizeof(char));
		*static_save = '\0';
	}
	while (!nl_position(static_save) && b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';
		static_save = make_save(static_save, buffer);
	}
	if (!*static_save || b_read < 0)
	{
		free(static_save);
		static_save = NULL;
		return (NULL);
	}
	ret = make_ret(static_save);
	static_save = to_next_line(static_save);
	return (ret);
}
