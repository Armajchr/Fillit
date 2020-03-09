/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:12:03 by armajchr          #+#    #+#             */
/*   Updated: 2019/05/27 16:33:12 by ekelkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void			gettetri(char *line, int *nbline, t_tetri *tab)
{
	int			i;
	static int	nbtetri = 0;
	static int	nbhash = 0;

	i = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			tab[nbtetri].x[nbhash] = i;
			tab[nbtetri].y[nbhash] = ((*nbline) - 1) % 5;
			tab[nbtetri].letter = nbtetri + 65;
			nbhash++;
			i++;
		}
		else
			i++;
	}
	if ((*nbline) % 5 == 0 && line[0] == '\0')
	{
		nbtetri++;
		nbhash = 0;
	}
	free(line);
}

static int		maxtab(int *tab)
{
	int max;
	int j;

	j = 1;
	max = tab[0];
	while (j < 4)
	{
		if (max < tab[j])
		{
			max = tab[j];
			j++;
		}
		else
			j++;
	}
	return (max);
}

static int		mintab(int *tab)
{
	int min;
	int j;

	j = 1;
	min = tab[0];
	while (j < 4)
	{
		if (min > tab[j])
		{
			min = tab[j];
			j++;
		}
		else
			j++;
	}
	return (min);
}

void			dimtetri(t_tetri *tab, int numtetri)
{
	int min;
	int max;

	max = maxtab(tab[numtetri].x);
	min = mintab(tab[numtetri].x);
	tab[numtetri].width = max - min + 1;
	max = maxtab(tab[numtetri].y);
	min = mintab(tab[numtetri].y);
	tab[numtetri].height = max - min + 1;
}

void			movetetri(t_tetri *tab, int numtetri)
{
	int i;
	int mini;
	int miny;

	i = 0;
	mini = mintab(tab[numtetri].x);
	miny = mintab(tab[numtetri].y);
	while (i < 4)
	{
		tab[numtetri].x[i] = tab[numtetri].x[i] - mini;
		tab[numtetri].y[i] = tab[numtetri].y[i] - miny;
		i++;
	}
}
