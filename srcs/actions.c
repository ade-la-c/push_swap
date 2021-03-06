/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:13:58 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/20 16:19:17 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_tabs *tabs, char *action)
{
	int	tmp;

	if (!ft_strcmp(action, "sa") || !ft_strcmp(action, "ss"))
	{
		tmp = tabs->sta[0];
		tabs->sta[0] = tabs->sta[1];
		tabs->sta[1] = tmp;
	}
	if (!ft_strcmp(action, "sb") || !ft_strcmp(action, "ss"))
	{
		tmp = tabs->stb[0];
		tabs->stb[0] = tabs->stb[1];
		tabs->stb[1] = tmp;
	}
}

static void	rotate(t_tabs *tabs, char *action)
{
	int	tmp;
	int	i;

	if (!ft_strcmp(action, "ra") || !ft_strcmp(action, "rr"))
	{
		i = -1;
		tmp = tabs->sta[0];
		while (++i + 1 < tabs->sizea)
			tabs->sta[i] = tabs->sta[i + 1];
		tabs->sta[i] = tmp;
	}
	if (!ft_strcmp(action, "rb") || !ft_strcmp(action, "rr"))
	{
		i = -1;
		tmp = tabs->stb[0];
		while (++i + 1 < tabs->sizeb)
			tabs->stb[i] = tabs->stb[i + 1];
		tabs->stb[i] = tmp;
	}
}

static void	reverse_rotate(t_tabs *tabs, char *action)
{
	int	tmp;
	int	i;

	if (!ft_strcmp(action, "rra") || !ft_strcmp(action, "rrr"))
	{
		i = tabs->sizea;
		tmp = tabs->sta[i - 1];
		while (--i > 0)
			tabs->sta[i] = tabs->sta[i - 1];
		tabs->sta[0] = tmp;
	}
	if (!ft_strcmp(action, "rrb") || !ft_strcmp(action, "rrr"))
	{
		i = tabs->sizeb;
		tmp = tabs->stb[i - 1];
		while (--i > 0)
			tabs->stb[i] = tabs->stb[i - 1];
		tabs->stb[0] = tmp;
	}
}

static void	push(int *src, int *dest, int sizea, int sizeb)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = src[0];
	if (!sizea)
		return ;
	while (i + 1 < sizea)
	{
		src[i] = src[i + 1];
		i++;
	}
	i = sizeb;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = tmp;
}

void	action(t_tabs *tabs, char *action, int bool)
{
	if (!ft_strcmp(action, "sa") || !ft_strcmp(action, "sb")
		|| !ft_strcmp(action, "ss"))
		swap(tabs, action);
	else if (!ft_strcmp(action, "ra") || !ft_strcmp(action, "rb")
		|| !ft_strcmp(action, "rr"))
		rotate(tabs, action);
	else if (!ft_strcmp(action, "rra") || !ft_strcmp(action, "rrb")
		|| !ft_strcmp(action, "rrr"))
		reverse_rotate(tabs, action);
	else if (!ft_strcmp(action, "pa"))
		push(tabs->stb, tabs->sta, tabs->sizeb--, tabs->sizea++);
	else if (!ft_strcmp(action, "pb"))
		push(tabs->sta, tabs->stb, tabs->sizea--, tabs->sizeb++);
	else
		exit_error("Error");
	if (bool == 2)
		return ;
	ft_putstr(action);
	ft_putchar('\n');
}
