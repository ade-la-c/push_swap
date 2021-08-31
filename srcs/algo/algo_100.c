/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:30:35 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/31 01:03:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_to_stb(t_tabs *tabs, int x, int bool)
{
	while (x > 0)
	{
		if (bool == 1)
		{
			action(tabs, "rra");
			x--;
		}
		else if (bool == 0)
		{
			action(tabs, "ra");
			x--;
		}
	}
	printf("## %d ##", tabs->sta[0]);
	action(tabs, "pb");
	printf("\n");
	return ;
}

static void	push_value(t_tabs *tabs, int posa, int posb)
{
	int	a;
	int	b;

	if (posa < tabs->sizea / 2)
		a = posa;
	else if (posa >= tabs->sizea / 2)
		a = tabs->sizea - posa;
	if (posb < tabs->sizea / 2)
		b = posb;
	else if (posb >= tabs->sizea / 2)
		b = tabs->sizea - posb;
	if (posa <= posb)
		push_to_stb(tabs, a, 0);
	else if (posa > posb)
		push_to_stb(tabs, b, 1);
}

static void	get_two_values(t_tabs *tabs, int *chunk)
{
	int	i;
	int	posa;
	int	posb;

	i = 0;
	while (i < tabs->sizea)
	{
		if (is_in_tab(tabs->sta[i], chunk, 20))
		{
			tabs->lowa = tabs->sta[i];
			break ;
		}
		i++;
	}
	posa = is_in_tab(tabs->lowa, tabs->sta, tabs->sizea);
	// i = tabs->sizea;
	i = 0;
	while (i < tabs->sizea)
	{
		if (is_in_tab(tabs->sta[i], chunk, 20) && tabs->sta[i] != tabs->lowa)
			tabs->lowb = tabs->sta[i];
		i++;
	}
	posb = is_in_tab(tabs->lowb, tabs->sta, tabs->sizea);
	push_value(tabs, posa, posb);
}



void	algo_100(t_tabs *tabs)
{
	int	i;
	int	j;

	i = 0;
	j = 20;
	sort_chunks(tabs);
	while (i < tabs->chunk)
	{
		while (tabs->sizeb < j)
		{
			get_two_values(tabs, tabs->chunks[i]);
			// push_value(tabs, );
		}
		j += 20;
		i++;
	}print_tab(tabs->stb, tabs->sizeb);
	return ;
}
