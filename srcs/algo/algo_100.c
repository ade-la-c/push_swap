/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:30:35 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/30 22:00:21 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void	push_value(t_tabs *tabs, int posa, int posb)
{
	if (posa <= tabs->sizea / 2)
		
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
			// push_value(tabs);
		}
		j += 20;
		i++;
	}
	return ;
}
