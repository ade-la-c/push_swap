/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:13:58 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/25 22:30:22 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_tabs *tabs, char *action)
{
	int	tmp;

	ft_putstr(action);
	ft_putchar('\n');
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
	ft_putchar('\n');
	if (!ft_strcmp(action, "ra") || !ft_strcmp(action, "rr"))
	{
		i = 0;
		tmp = tabs->sta[i];
		while (tabs->sta[i + 1])
		{
			tabs->sta[i] = tabs->sta[i + 1];
			i++;
		}
		tabs->sta[i] = tmp;
	}
	if (!ft_strcmp(action, "rb") || !ft_strcmp(action, "rr"))
	{
		i = 0;
		tmp = tabs->stb[i];
		while (tabs->stb[i + 1])
		{
			tabs->stb[i] = tabs->stb[i + 1];
			i++;
		}
		tabs->stb[i] = tmp;
	}
}

static void	reverse_rotate(t_tabs *tabs, char *action)
{
	int	tmp;
	int	i;

	ft_putstr(action);
	ft_putchar('\n');
	if (!ft_strcmp(action, "rra") || !ft_strcmp(action, "rrr"))
	{
		i = tabsize(tabs->sta);
		tmp = tabs->sta[i];
		while (i - 1 > 0)
		{
			tabs->sta[i] = tabs->sta[i - 1];
			i--;
		}
	}
	if (!ft_strcmp(action, "rrb") || !ft_strcmp(action, "rrr"))
	{
		i = tabsize(tabs->stb);
		tmp = tabs->stb[i];
		while (i - 1 > 0)
		{
			tabs->stb[i] = tabs->stb[i - 1];
			i--;
		}
	}
}

static void	push(t_tabs *tabs, char *action)
{
	int	tmp;
	int	i;

	ft_putstr(action);
	ft_putchar('\n');
	if (!ft_strcmp(action, "pa"))
	{
		i = 0;
		tmp = tabs->stb[0];
		while (tabs->stb[i + 1])
		{
			tabs->stb[i] = tabs->stb[i + 1];
			i++;
		}
		i = tabsize(tabs->sta);
		while (i - 1 > 0)
		{
			tabs->sta[i] = tabs->sta[i - 1];
			i--;
		}
		tabs->sta[0] = tmp;
	}
	else if (!ft_strcmp(action, "pb"))
	{
		i = 0;
		tmp = tabs->sta[0];
		while (tabs->sta[i + 1])
		{
			tabs->sta[i] = tabs->sta[i + 1];
			i++;
		}
		i = tabsize(tabs->stb);
		while (i - 1 > 0)
		{
			tabs->stb[i] = tabs->stb[i - 1];
			i--;
		}
		tabs->stb[0] = tmp;
	}
}

void	action(t_tabs *tabs, char *action)
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
	else if (!ft_strcmp(action, "pa") || !ft_strcmp(action, "pb"))
		push(tabs, action);
	else
		exit_error("wrong action param");
}
