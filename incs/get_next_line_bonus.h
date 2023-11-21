/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:21:48 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/21 22:06:13 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_glist
{
	int				fd;
	char			leave[BUFFER_SIZE + 1];
	struct s_glist	*next;
}	t_glist;

char	*get_next_line(int fd);
t_glist	*gn_lstadd_back(t_glist **head, int fd);
char	*gn_setstr(char	*leave, t_glist *cur);
char	*read_n_join(char *toss, int fd, int size);
char	*gn_newstr(char *toss, int *size);
int		gn_strcat(char *toss, char *buf);
char	*gn_substr(char *toss, t_glist *cur, int len);
int		gn_check(char *toss);
void	gn_lstdel(t_glist **head, int fd);

#endif
