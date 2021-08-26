/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:13:58 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/26 20:37:42 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_tabs *tabs, char *action)
{
	int	tmp;

	ft_putstr(action);
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

	ft_putstr(action);
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

	ft_putstr(action);
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

static void	push(t_tabs *tabs, char *action)
{
	int	tmp;
	int	i;

	ft_putstr(action);
	i = -1;
	if (!ft_strcmp(action, "pa"))
	{
		tmp = tabs->stb[0];
		while (tabs->stb[++i + 1])
			tabs->stb[i] = tabs->stb[i + 1];
		i = tabs->sizea + 1;
		while (--i - 1 > 0)
			tabs->sta[i] = tabs->sta[i - 1];
		tabs->sta[0] = tmp;
		tabs->sizea += 1;
		tabs->sizeb -= 1;
	}
	else if (!ft_strcmp(action, "pb"))
	{
		tmp = tabs->sta[0];
		while (tabs->sta[++i + 1])
			tabs->sta[i] = tabs->sta[i + 1];
		i = tabs->sizeb + 1;
		while (--i - 1 > 0)
			tabs->stb[i] = tabs->stb[i - 1];
		tabs->stb[0] = tmp;
		tabs->sizea -= 1;
		tabs->sizeb += 1;
	}
}

void	action(t_tabs *tabs, char *action)
{
	if (!ft_strcmp(action, "sa") || !ft_strcmp(action, "sb")
		|| !ft_strcmp(action, "ss"))
	{
		swap(tabs, action);
		ft_putchar('\n');
	}
	else if (!ft_strcmp(action, "ra") || !ft_strcmp(action, "rb")
		|| !ft_strcmp(action, "rr"))
	{
		rotate(tabs, action);
		ft_puchar('\n');
	}
	else if (!ft_strcmp(action, "rra") || !ft_strcmp(action, "rrb")
		|| !ft_strcmp(action, "rrr"))
	{
		reverse_rotate(tabs, action);
		ft_putchar('\n');
	}
	else if (!ft_strcmp(action, "pa") || !ft_strcmp(action, "pb"))
	{
		push(tabs, action);
		ft_putchar('\n');
	}
	else
		exit_error("wrong action param");
}
