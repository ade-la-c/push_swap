/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:57:40 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/15 14:22:17 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_order(t_tabs *tabs)
{
	int	i;

	i = 0;
	if (tabs->sizeb)
		return (0);
	while (i < tabs->sizea - 1)
	{
		if (tabs->sta[i] < tabs->sta[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**strs;
	t_tabs	*tabs;
	char	*line;

	tabs = ft_calloc(1, sizeof(t_tabs));
	if (ac != 2)
		exit_error("Error");
	strs = ft_split(av[1], ' ');
	if (!strs || !strs[1])
		exit_error("Error");
	check_stack(strs);
	tabs->sta = strs_to_tab(strs, tabs);
	if (check_order(tabs))
		ft_putstr("OK\n");
	while (get_next_line(0, &line) > 0)
	{
		action(tabs, line, 2);
	}
	if (check_order(tabs))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
