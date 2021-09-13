/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:20:52 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/13 15:27:52 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_back(t_tabs *tabs)
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

static void	push_value(t_tabs *tabs, int num, int i, int pos)
{//printf("||%d||\n", pos);
	while (i > 0 && pos != 0)
	{
		if (pos <= tabs->sizea / 2)
			action(tabs, "ra");
		else
			action(tabs, "rra");
		i--;
	}
	// printf("|%d|%d|\n", i, tabs->sta[0]);
	if (num == tabs->sta[0])
	{
		// sort_stb(tabs);
		action(tabs, "pb");
		// action(tabs, "rb");
	}
	else{	print_tab(tabs->sta, tabs->sizea, "sta");
			print_tab(tabs->stb, tabs->sizeb, "stb");
		exit_error("push_value doesn't work properly");}
}

static void	push_correct_value(t_tabs *tabs)
{
	int	posa;
	int	posb;
	int	a;
	int	b;

	posa = is_in_tab(tabs->lowa, tabs->sta, tabs->sizea);
	posb = is_in_tab(tabs->lowb, tabs->sta, tabs->sizea);
	if (posa == -5 || posb == -5){
	print_tab(tabs->sta, tabs->sizea, "sta");
	print_tab(tabs->stb, tabs->sizeb, "stb");
		exit_error("pos problem");}
	if (posa <= tabs->sizea / 2)
		a = posa;
	else
		a = tabs->sizea - posa;
	if (posb <= tabs->sizea / 2)
		b = posb;
	else
		b = tabs->sizea - posb;			printf("A:%d B:%d\n", a, b);
	if (a <= b){printf(" %d+", a);
		push_value(tabs, tabs->lowa, a, posa);
		}
	else if (a > b){printf(" %d~", b);
		push_value(tabs, tabs->lowb, b, posb);
		}
	return ;
}

static void	get_two_values(t_tabs *tabs, int *chunk, int chunksize)
{
	int	i;

	i = 0;
	while (i < tabs->sizea)
	{
		if (is_in_tab(tabs->sta[i], chunk, chunksize) >= 0)
		{
			tabs->lowa = tabs->sta[i];
			break ;
		}
		i++;
	}
	i = 0;
	while (i < tabs->sizea)
	{
		if (is_in_tab(tabs->sta[i], chunk, chunksize) >= 0)
			tabs->lowb = tabs->sta[i];
		i++;
	}
	if (tabs->lowa == tabs->stb[0] && tabs->lowb == tabs->stb[0])
		exit_error("get two values");
	printf("lowA %d, lowB %d\n", tabs->lowa, tabs->lowb);
}

void	big_algo(t_tabs *tabs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	get_chunks(tabs);
	while (i < tabs->chunk - 1)
	{
		j += tabs->chunksize;
		while (tabs->sizeb < j)
		{
			get_two_values(tabs, tabs->chunks[i], tabs->chunksize);
			push_correct_value(tabs);
		}
		i++;
	}
	j += tabs->lastchunksize;
	while (tabs->sizeb < j)
	{
		get_two_values(tabs, tabs->chunks[i], tabs->lastchunksize);
		push_correct_value(tabs);
	}
	while (tabs->sizeb > 0)
	{
		push_back(tabs);
	}
	print_tab(tabs->stb, tabs->sizeb, "stb after algo 100");
}
