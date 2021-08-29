/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:58:21 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/29 16:55:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_lower_values(t_tabs *tabs)
{
	while (tabs->sizea == 5)
	{
		if (tabs->lowa == tabs->sta[0])
			action(tabs, "pb");
		else if (tabs->lowa != tabs->sta[3] && tabs->lowa != tabs->sta[4])
			action(tabs, "ra");
		else if (tabs->lowa != tabs->sta[1] && tabs->lowa != tabs->sta[2])
			action(tabs, "rra");
	}
	while (tabs->sizea == 4)
	{
		if (tabs->lowb == tabs->sta[0])
			action(tabs, "pb");
		else if (tabs->lowb != tabs->sta[2] && tabs->lowb != tabs->sta[3])
			action(tabs, "ra");
		else if (tabs->lowb != tabs->sta[1])
			action(tabs, "rra");
	}print_tab(tabs->stb, tabs->sizeb);
	return ;
}

void	algo_5(t_tabs *tabs)
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
	action(tabs, "pa");
	action(tabs, "pa");
	return ;
}
