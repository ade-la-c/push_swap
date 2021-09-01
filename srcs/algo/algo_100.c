/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:30:35 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/01 20:29:41 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static void	push_to_stb(t_tabs *tabs, int x, int bool)
// {
// 	while (x > 0)
// 	{
// 		if (bool == 1)
// 		{
// 			action(tabs, "rra");
// 			x--;
// 		}
// 		else if (bool == 0)
// 		{
// 			action(tabs, "ra");
// 			x--;
// 		}
// 	}
// 	printf("## %d ##", tabs->sta[0]);
// 	action(tabs, "pb");
// 	return ;
// }

static void	push_value(t_tabs *tabs, int num, int i, int pos)
{printf("||%d||", pos);
	while (i > 0 && pos != 0)
	{
		if (pos <= tabs->sizea / 2)
			action(tabs, "ra");
		else
			action(tabs, "rra");
		i--;
	}
	printf("|%d|%d|\n", i, tabs->sta[0]);
	if (num == tabs->sta[0]){
		action(tabs, "pb");}
	else{	print_tab(tabs->sta, tabs->sizea, "sta");
			print_tab(tabs->stb, tabs->sizeb, "stb");
		exit_error("push_value doesn't work properly");}
	return ;
}

static void	push_correct_value(t_tabs *tabs)
{
	int	posa;
	int	posb;
	int	a;
	int	b;

	posa = is_in_tab(tabs->lowa, tabs->sta, tabs->sizea);
	posb = is_in_tab(tabs->lowb, tabs->sta, tabs->sizea);
	if (posa <= tabs->sizea / 2)
		a = posa - 1;
	else
		a = tabs->sizea - posa + 1;
	if (posb <= tabs->sizea / 2)
		b = posb - 1;
	else
		b = tabs->sizea - posb + 1;
	if (a <= b){printf("+");
		push_value(tabs, tabs->lowa, a, posa);}
	else if (a > b){printf(" %d~", posb);
		push_value(tabs, tabs->lowb, b, posb);}
	return ;
}

static void	get_two_values(t_tabs *tabs, int *chunk)
{
	int	i;

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
	// i = tabs->sizea;
	i = 0;
	while (i < tabs->sizea)
	{
		if (is_in_tab(tabs->sta[i], chunk, 20) && tabs->sta[i] != tabs->lowa)
			tabs->lowb = tabs->sta[i];
		i++;
	}
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
			push_correct_value(tabs);
		}
		j += 20;
		i++;
	}print_tab(tabs->stb, tabs->sizeb, "sta after algo 100");
	return ;
}
