#include <stddef.h>
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char		*get_next_line(int fd);
char		*make_save(char *static_save, char *buffer);
char		*make_line(char *static_save);
char		*to_next_line(char *old_save);
size_t		s_len(char *str);
int			nl_position(char *str);

#endif
