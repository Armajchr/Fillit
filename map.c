/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekelkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:33:21 by ekelkel           #+#    #+#             */
/*   Updated: 2019/05/27 16:33:26 by ekelkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char		**initmap(int size)
{
	int		i;
	int		j;
	char	**map;
	int		t;

	i = 0;
	t = size;
	if (!(map = (char**)malloc(sizeof(char*) * (t))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (t))))
			return (NULL);
		j = 0;
		map[i][size] = '\0';
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void		freemap(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void**)&(map[i]));
		i++;
	}
	ft_memdel((void**)&map);
}

void		printmap(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putendl(map[i]);
		i++;
	}
}
