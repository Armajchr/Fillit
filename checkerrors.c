/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:07:45 by armajchr          #+#    #+#             */
/*   Updated: 2019/05/31 11:10:29 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void			cpt0(int *cpt)
{
	int i;

	i = 0;
	while (i < 6)
	{
		cpt[i] = 0;
		i++;
	}
}

static int		check2(char *line, int *cpt)
{
	int		i;
	int		nbhash;

	i = 0;
	nbhash = cpt[0];
	while (line[i])
	{
		if (line[i] == '#')
		{
			if (cpt[0] != nbhash && line[i - 1] == '#')
				cpt[1]++;
			if (cpt[i + 2] == 1)
				cpt[1]++;
			cpt[0]++;
			cpt[i + 2] = 1;
		}
		else
			cpt[i + 2] = 0;
		if (cpt[0] > 4)
			return (-1);
		i++;
	}
	if ((cpt[1] < 3 || cpt[1] > 4) && cpt[0] == 4)
		return (-1);
	return (0);
}

static int		check1(char *line, int *nbline, int *nbtetri, int *cpt)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			return (-1);
		i++;
	}
	if (i != 4 && i != 0)
		return (-1);
	(*nbline)++;
	if ((*nbline) % 5 == 0 && line[0] == '\0')
	{
		(*nbtetri)++;
		cpt0(cpt);
		return (0);
	}
	else if ((*nbline) % 5 != 0 && i == 4)
		return (check2(line, cpt));
	return (1);
}

int				ft_checkerrors(char *file, t_tetri *tab)
{
	int		fd;
	char	*line;
	int		nbline;
	int		nbtetri;
	int		cpt[6];

	nbline = 0;
	nbtetri = 0;
	cpt0(cpt);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		if (check1(line, &nbline, &nbtetri, cpt) == -1 || nbtetri > 26)
		{
			free(line);
			return (-1);
		}
		else
			gettetri(line, &nbline, tab);
	}
	free(line);
	if (((nbline % 5 != 4) && (nbtetri == 0))|| close(fd) == -1)
		return (-1);
	return (nbtetri);
}
