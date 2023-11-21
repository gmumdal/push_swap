/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:37:28 by hyeongsh          #+#    #+#             */
/*   Updated: 2023/11/21 22:06:42 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gn_check(char *toss)
{
	if (toss == 0)
		return (0);
	while (*toss)
	{
		if (*toss == '\n')
			return (0);
		toss++;
	}
	return (1);
}

void	gn_lstdel(t_glist **head, int fd)
{
	t_glist	*cur;
	t_glist	*tmp;

	cur = *head;
	if (cur == NULL || cur->fd == fd)
	{
		if (cur->fd == fd)
			*head = cur->next;
		free(cur);
		return ;
	}
	while (cur->next->fd != fd && cur != NULL)
		cur = cur->next;
	if (cur == NULL)
		return ;
	tmp = cur->next;
	cur->next = tmp->next;
	free(tmp);
}

char	*gn_newstr(char *toss, int *size)
{
	char	*twice;
	int		i;

	*size *= 2;
	twice = (char *)malloc(*size + 1);
	if (twice == 0)
	{
		free(toss);
		return (0);
	}
	i = 0;
	while (toss[i] != 0)
	{
		twice[i] = toss[i];
		i++;
	}
	twice[i] = 0;
	free(toss);
	return (twice);
}

int	gn_strcat(char *toss, char *buf)
{
	int	flag;

	flag = 0;
	if (toss == 0)
		return (1);
	while (*toss != 0)
		toss++;
	while (*buf != 0)
	{
		if (*buf == '\n')
			flag = 1;
		*toss++ = *buf++;
	}
	*toss = 0;
	return (flag);
}
