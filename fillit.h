/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:10:41 by armajchr          #+#    #+#             */
/*   Updated: 2019/05/21 15:37:40 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_tetri
{
	int			x[4];
	int			y[4];
	int			height;
	int			width;
	char		letter;
}						t_tetri;

void					cpt0(int *cpt);
int						ft_checkerrors(char *file, t_tetri *tab);
void					gettetri(char *line, int *nbline, t_tetri *tab);
void					dimtetri(t_tetri *tab, int numtetri);
char					**initmap(int size);
int						ft_sqrt(int nb);
void					movetetri(t_tetri *tab, int numtetri);
void					fillit(t_tetri	*tab, int nbtetri);
void					freemap(char **map, int size);
void					printmap(char **map, int size);
int						solver(char **map, t_tetri *tab, int size, int nbtetri);

#endif
