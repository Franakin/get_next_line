#include <stddef.h>
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

char		*get_next_line(int fd);
char		*make_save(char *static_save, char *buffer);
char		*make_ret(char *static_save);
size_t		s_len(char *str);
int			nl_position(char *str);
int			nl_or_end(char *static_save);

#endif
