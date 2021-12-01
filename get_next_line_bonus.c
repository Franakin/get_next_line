#include "get_next_line_bonus.h"
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

char	*to_next_line(char *old_save)
{
	char	*new_save;
	int		i;
	int		k;

	k = 0;
	if (!old_save)
		return (NULL);
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
	static char	*static_save[1024];
	char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	int			b_read;

	if (fd < 0 || fd > 1024)
		return (NULL);
	b_read = 1;
	if (!static_save[fd])
	{
		static_save[fd] = (char *)malloc(sizeof(char));
		*static_save[fd] = '\0';
	}
	while (!nl_position(static_save[fd]) && b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';
		static_save[fd] = make_save(static_save[fd], buffer);
	}
	static_save[fd] = check_error(static_save[fd], b_read);
	ret = make_ret(static_save[fd]);
	static_save[fd] = to_next_line(static_save[fd]);
	return (ret);
}
