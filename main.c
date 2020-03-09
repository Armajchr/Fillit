/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:06:10 by armajchr          #+#    #+#             */
/*   Updated: 2019/09/11 16:28:54 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>

static t_tetri	*set_tab(t_tetri *tab)
{
	int i;

	i = 0;
	while (i < 26)
	{
		cpt0(tab[i].x);
		cpt0(tab[i].y);
		tab[i].height = 0;
		tab[i].width = 0;
		tab[i].letter = 0;
		i++;
	}
	return (tab);
}

void			fillit(t_tetri *tab, int nbtetri)
{
	char	**map;
	int		size;

	size = ft_sqrt(nbtetri * 4);
	map = initmap(size);
	while (!solver(map, tab, size, nbtetri))
	{
		freemap(map, size);
		size++;
		map = initmap(size);
	}
	printmap(map, size);
	freemap(map, size);
}

static int		errors(int nbtetri, t_tetri *tab)
{
	if (nbtetri == 0)
	{
		ft_putstr("error\n");
		free(tab);
		return (-1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_tetri	*tab;
	int		i;
	int		nbtetri;

	if (ac != 2)
	{
		ft_putstr("usage: [./fillit] [file_to_test] exe target_file");
		return (0);
	}
	if (!(tab = (t_tetri*)malloc(sizeof(t_tetri) * 26)))
		return (0);
	tab = set_tab(tab);
	nbtetri = ft_checkerrors(av[1], tab) + 1;
	if (errors(nbtetri, tab) == -1)
		return (-1);
	i = 0;
	while (i < nbtetri)
	{
		dimtetri(tab, i);
		movetetri(tab, i);
		i++;
	}
	fillit(tab, nbtetri);
	free(tab);
	return (0);
}
