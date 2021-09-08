/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:00:19 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/08 19:07:57 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	split_chunks(t_tabs *tabs, int *sorted_tab)
{
	int	i;
	int	j;
	int	k;
	int	chunksize;

	i = 0;
	k = 0;
	chunksize = tabs->sizea / tabs->chunk;
	while (i < tabs->chunk)
	{
		j = -1;
		while (++j < chunksize)
			tabs->chunks[i][j] = sorted_tab[j + k];
		k += chunksize;
		i++;
	}
	j = -1;
	while (++j < tabs->sizea % tabs->chunk)
		tabs->chunks[i][j] = sorted_tab[j + k];
}

//	sort_tab creates a sorted array that will be useful to fill the chunks

static void	fill_chunks(t_tabs *tabs)
{
	int	*sorted_tab;
	int	i;

	sorted_tab = (int *)malloc(sizeof(int) * tabs->sizea);
	if (!sorted_tab)
		exit_error("malloc failed");
	i = -1;
	while (++i < tabs->sizea)
		sorted_tab[i] = tabs->sta[i];
	ft_sort_int_tab(sorted_tab, tabs->sizea);
	split_chunks(tabs, sorted_tab);
}

//	nbr_of_chunks defines how many chunks are used according to SIZEA

static int	nbr_of_chunks(int i)
{
	if (i < 5)
		return (1);
	else if (i < 12)
		return (3);
	else if (i < 99)
		return (5);
	else if (i < 495)
		return (9);
	else
		return (16);
}

//	get_chunks is the main function used to define & make chunks

void	get_chunks(t_tabs *tabs)
{
	int	i;
	int	tmp;
	int	chunksize;
	int	lastchunksize;

	i = 0;
	tmp = tabs->sizea;
	tabs->chunk = nbr_of_chunks(tabs->sizea) - 1;
	tabs->chunks = (int **)malloc(sizeof(int *) * tabs->chunk + 1);
	if (!tabs->chunks)
		exit_error("malloc failed");
	chunksize = tabs->sizea / tabs->chunk;
	if (tabs->sizea % tabs->chunk)
		lastchunksize = tabs->sizea % tabs->chunk;
	else
		lastchunksize = tabs->sizea / tabs->chunk;
	while (i < tabs->chunk)
	{
		tabs->chunks[i] = (int *)malloc(sizeof(int) * chunksize);
		if (!tabs->chunks[i])
			exit_error("malloc failed");
		tmp -= chunksize;
		i++;
	}
	if ()
		tabs->chunks[i] = (int *)malloc(sizeof(int) * tabs->sizea % tabs->chunk);
		if (!tabs->chunks[i])
			exit_error("malloc failed");
	fill_chunks(tabs);
}
