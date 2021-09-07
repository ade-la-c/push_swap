/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:45:49 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/07 17:59:31 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
/*
void	sort_stb(t_tabs *tabs)
{
	int	i;
	int	low;
	int	pos;
	int	a;

	if (!tabs->sizeb)
		return ;
	i = 0;
	low = tabs->stb[i];
	while (i < tabs->sizeb)
	{
		if (low > tabs->stb[i])
			low = tabs->stb[i];
		i++;
	}printf("/~%d~\\\n", low);
	pos = is_in_tab(low, tabs->stb, tabs->sizeb);
	if (pos < 0)
		exit_error("sort stb, pos is negative");
	if (pos <= tabs->sizeb / 2)
	{
		a = pos;
		while (a > 0)
		{
			action(tabs, "rb");
			a--;
		}
	}
	else
	{
		a = tabs->sizeb - pos;
		while (a > 0)
		{
			action(tabs, "rrb");
			a--;
		}
	}
	if (low != tabs->stb[0])
		exit_error("wtf sort_b ?");
	return ;
}
*/

void	push_back(t_tabs *tabs)
{
	int		i;
	int		high;
	int		move;
	char	*str;

	i = -1;
	high = tabs->stb[0];
	str = "rb";
	while (++i < tabs->sizeb)
		if (tabs->stb[i] > high)
			high = tabs->stb[i];
	if (is_in_tab(high, tabs->stb, tabs->sizeb) <= tabs->sizeb / 2)
		move = is_in_tab(high, tabs->stb, tabs->sizeb) + 1;
	else
	{
		move = tabs->sizeb - is_in_tab(high, tabs->stb, tabs->sizeb) + 1;
		str = "rrb";
	}
	while (--move > 0)
		action(tabs, str);
	if (high == tabs->stb[0])
		action(tabs, "pa");
	else
		exit_error("push_back tsé");
}
