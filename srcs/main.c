/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:51:24 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/14 23:41:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**strs;
	t_tabs	*tabs;

	tabs = ft_calloc(1, sizeof(t_tabs));
	if (ac != 2)
		exit_error("too many / few arguments");
	strs = ft_split(av[1], ' ');
	check_stack(strs);
	if (!strs || !strs[1])
		exit_error("stack is not long enough");
	tabs->sta = strs_to_tab(strs, tabs);
	// print_tab(tabs->sta, tabs->sizea, "sta main");
	if (tabs->sizea <= 5)
		lil_algo(tabs);
	else
		big_algo(tabs);
	// print_tab(tabs->sta, tabs->sizea, "sta main end");
	return (0);
}
