/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:57:40 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/15 01:17:23 by root             ###   ########.fr       */
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
	{//printf("ee\n");
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
	char	*lines;
	char	*line;

	if (check_order(tabs))
		ft_putstr("OK\n");
	tabs = ft_calloc(1, sizeof(t_tabs));
	if (ac != 2)
		exit_error("Error");
	strs = ft_split(av[1], ' ');
	if (!strs || !strs[1])
		exit_error("Error");
	check_stack(strs);
	tabs->sta = strs_to_tab(strs, tabs);
	while (get_next_line(1, &line) > 0)
	{
		action(tabs, line, 2);
	}
	if (check_order(tabs))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
