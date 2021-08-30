/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:33:56 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/30 20:46:16 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_error(char *error)
{
	ft_putstr("ERROR : ");
	ft_putstr(error);
	ft_putchar('\n');
	exit(0);
}

static void	fill_chunks(t_tabs *tabs, int *sorted_tab)
{
	int	i;
	int	j;
	int	k;

	tabs->chunks = (int **)malloc(tabs->chunk * sizeof(int *));
	if (!tabs->chunks)
		exit_error("malloc failed");
	i = -1;
	k = 0;
	while (++i < tabs->chunk)
	{
		tabs->chunks[i] = (int *)malloc(20 * sizeof(int));
		if (!tabs->chunks[i])
			exit_error("malloc failed");
		j = -1;
		while (++j < 20)
			tabs->chunks[i][j] = sorted_tab[j + k];
		k += 20;
	}
}

void	sort_chunks(t_tabs *tabs)
{
	int	*sorted_tab;
	int	i;

	sorted_tab = (int *)malloc(tabs->sizea * sizeof(int));
	if (!sorted_tab)
		exit_error("malloc failed");
	if (tabs->sizea == 100)
		tabs->chunk = 5;
	else if (tabs->sizea == 500)
		tabs->chunk = 25;
	else
		exit_error("how many chunks ?");
	i = -1;
	while (++i < tabs->sizea)
		sorted_tab[i] = tabs->sta[i];
	ft_sort_int_tab(sorted_tab, tabs->sizea);
	fill_chunks(tabs, sorted_tab);
}

int	is_in_tab(int n, int *tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (tab[i] == n)
			return (i + 1);
	return (0);
}

// temporary

void	print_tab(int *tab, int tabsize)
{
	int	i;

	i = 0;
	while (i < tabsize)
	{
		printf("[%d]", tab[i]);
		i++;
	}
	printf("\n---\n");
	return ;
}
