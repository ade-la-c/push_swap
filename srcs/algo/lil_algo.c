/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:58:21 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/15 00:20:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_lower_values(t_tabs *tabs)
{
	while (tabs->sizea == 5)
	{
		if (tabs->lowa == tabs->sta[0])
			action(tabs, "pb", 1);
		else if (tabs->lowa != tabs->sta[3] && tabs->lowa != tabs->sta[4])
			action(tabs, "ra", 1);
		else if (tabs->lowa != tabs->sta[1] && tabs->lowa != tabs->sta[2])
			action(tabs, "rra", 1);
	}
	while (tabs->sizea == 4)
	{
		if (tabs->lowb == tabs->sta[0])
			action(tabs, "pb", 1);
		else if (tabs->lowb != tabs->sta[2] && tabs->lowb != tabs->sta[3])
			action(tabs, "ra", 1);
		else if (tabs->lowb != tabs->sta[1])
			action(tabs, "rra", 1);
	}
	return ;
}

static void	algo_3(t_tabs *tabs)
{
	if ((tabs->sta[0] < tabs->sta[1] && tabs->sta[1] > tabs->sta[2]
			&& tabs->sta[0] < tabs->sta[2]) || (tabs->sta[0] > tabs->sta[1]
			&& tabs->sta[1] < tabs->sta[2] && tabs->sta[0] < tabs->sta[2])
		|| (tabs->sta[0] > tabs->sta[1] && tabs->sta[1] > tabs->sta[2]
			&& tabs->sta[0] > tabs->sta[2]))
		action(tabs, "sa", 1);
	if (tabs->sta[0] < tabs->sta[1] && tabs->sta[1] > tabs->sta[2]
		&& tabs->sta[0] > tabs->sta[2])
		action(tabs, "rra", 1);
	if (tabs->sta[0] > tabs->sta[1] && tabs->sta[1] < tabs->sta[2]
		&& tabs->sta[0] > tabs->sta[2])
		action(tabs, "ra", 1);
	return ;
}

static void	algo_4(t_tabs *tabs)
{
	int	tab[4];
	int	i;

	i = -1;
	while (++i < 4)
		tab[i] = tabs->sta[i];
	ft_sort_int_tab(tab, 4);
	tabs->lowb = tab[0];
	push_lower_values(tabs);
	algo_3(tabs);
	action(tabs, "pa", 1);
	return ;
}

static void	algo_5(t_tabs *tabs)
{
	int	tab[5];
	int	i;

	i = -1;
	while (++i < 5)
		tab[i] = tabs->sta[i];
	ft_sort_int_tab(tab, 5);
	tabs->lowa = tab[0];
	tabs->lowb = tab[1];
	push_lower_values(tabs);
	algo_3(tabs);
	action(tabs, "pa", 1);
	action(tabs, "pa", 1);
	return ;
}

void	lil_algo(t_tabs *tabs)
{
	if (tabs->sizea == 2 && tabs->sta[0] > tabs->sta[1])
		action(tabs, "sa", 1);
	else if (tabs->sizea == 3)
		algo_3(tabs);
	else if (tabs->sizea == 4)
		algo_4(tabs);
	else if (tabs->sizea == 5)
		algo_5(tabs);
}
