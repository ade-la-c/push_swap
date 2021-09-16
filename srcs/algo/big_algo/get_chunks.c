/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:00:19 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/16 12:10:46 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//	split_chunks writes inside each chunk

static void	split_chunks(t_tabs *tabs, int *sorted_tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < tabs->chunk - 1)
	{
		j = -1;
		while (++j < tabs->chunksize)
			tabs->chunks[i][j] = sorted_tab[j + k];
		k += tabs->chunksize;
		i++;
	}
	j = -1;
	while (++j < tabs->lastchunksize)
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
	free(sorted_tab);
}

//	nbr_of_chunks defines how many chunks are used according to SIZEA

static int	nbr_of_chunks(int i)
{
	if (i < 12)
		return (3);
	else if (i < 99)
		return (5);
	else if (i < 495)
		return (7);
	else
		return (15);
}

//	get_chunks is the main function used to define & make chunks

void	get_chunks(t_tabs *tabs)
{
	int	i;

	i = -1;
	tabs->chunk = nbr_of_chunks(tabs->sizea);
	tabs->chunks = (int **)malloc(sizeof(int *) * tabs->chunk);
	if (!tabs->chunk)
		exit_error("malloc failed");
	if (!tabs->sizea % tabs->chunk)
	{
		tabs->chunksize = tabs->sizea / tabs->chunk;
		tabs->lastchunksize = tabs->sizea / tabs->chunk;
	}
	else
	{
		tabs->chunksize = tabs->sizea / (tabs->chunk - 1);
		tabs->lastchunksize = tabs->sizea % (tabs->chunk - 1);
	}
	while (++i < tabs->chunk - 1)
	{
		tabs->chunks[i] = (int *)malloc(sizeof(int) * tabs->chunksize);
		if (!tabs->chunks[i])
			exit_error("malloc failed");
	}
	tabs->chunks[i] = (int *)malloc(sizeof(int) * tabs->lastchunksize);
	fill_chunks(tabs);
}
