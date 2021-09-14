/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:57:40 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/14 20:46:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**strs;
	t_tabs	*tabs;
	char	*line;

	tabs = ft_calloc(1, sizeof(t_tabs));
	if (ac != 2)
		exit_error("Error");
	strs = ft_split(av[1], ' ');
	check_stack(strs);
	if (!strs)
		exit_error("malloc failed");
	tabs->sta = strs_to_tab(strs, tabs);
	while (get_next_line(1, &line) > 0)
		action(tabs, line);
	return (0);
}