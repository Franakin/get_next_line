#include <stddef.h>
#include <stdlib.h>

int	nl_position(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	s_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nl_or_end(char *static_save)
{
	int	split_pos;

	split_pos = nl_position(static_save);
	if (split_pos == 0)
		split_pos = s_len(static_save);
	return (split_pos);
}

char	*make_save(char *save, char *buffer)
{
	char	*new_save;
	int		i;

	new_save = (char *)malloc(sizeof(char) * (s_len(save) + s_len(buffer) + 1));
	if (!new_save)
		return (NULL);
	i = 0;
	while (save[i])
	{
		new_save[i] = save[i];
		i++;
	}
	free(save);
	while (*buffer)
	{
		new_save[i] = *buffer;
		i++;
		buffer++;
	}
	new_save[i] = '\0';
	return (new_save);
}

char	*make_ret(char *static_save)
{
	char	*ret;
	int		split_pos;

	if (!static_save)
		return (NULL);
	split_pos = nl_or_end(static_save);
	ret = (char *)malloc(sizeof(char) * (split_pos + 1));
	if (!ret)
		return (NULL);
	ret[split_pos] = '\0';
	split_pos--;
	while (split_pos >= 0)
	{
		ret[split_pos] = static_save[split_pos];
		split_pos--;
	}
	return (ret);
}
