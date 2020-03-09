/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekelkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:32:45 by ekelkel           #+#    #+#             */
/*   Updated: 2019/05/27 16:33:41 by ekelkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				ft_sqrt(int nb)
{
	int	racine;

	racine = 1;
	if (racine <= 0)
		return (0);
	while (racine * racine <= nb)
	{
		if (racine * racine == nb)
			return (racine);
		racine++;
	}
	racine--;
	return (racine);
}

static void		placetetri(t_tetri *tetri, char **map, int y, int x)
{
	int		k;

	k = 0;
	while (k < 4)
	{
		map[tetri->y[k] + y][tetri->x[k] + x] = tetri->letter;
		k++;
	}
}

static int		checkplace(t_tetri *tetri, char **map, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (x + tetri->x[i] < 0 || y + tetri->y[i] < 0)
			return (0);
		if (map[tetri->y[i] + y][tetri->x[i] + x] != '.')
			return (0);
		i++;
	}
	placetetri(tetri, map, y, x);
	return (1);
}

static void		deltetri(t_tetri *tetri, char **map, int x, int y)
{
	char	c;

	c = tetri->letter;
	tetri->letter = '.';
	placetetri(tetri, map, y, x);
	tetri->letter = c;
}

int				solver(char **map, t_tetri *tab, int size, int nbtetri)
{
	int		x;
	int		y;

	y = 0;
	if (tab->letter < 'A' || tab->letter > 'Z')
		return (-1);
	while (y <= size - tab->height)
	{
		x = -1;
		while (x++ < size)
		{
			if (checkplace(tab, map, x, y))
			{
				if (nbtetri == 1 || (solver(map, tab + 1, size, nbtetri - 1)))
					return (1);
				else
				{
					deltetri(tab, map, x, y);
					nbtetri++;
				}
			}
		}
		y++;
	}
	return (0);
}
