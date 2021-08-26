/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:51:24 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/26 18:53:50 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*strs_to_tab(char **strs, t_tabs *tabs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	tabs->sizea = i;
	tabs->sta = (int *)malloc(sizeof(int) * i);//printf("->%d\n", i);exit(0);
	if (!tabs->sta)
		exit_error("malloc failed");
	i = 0;
	while (strs[i])
	{
		tabs->sta[i] = ft_atoi(strs[i]);
		i++;
	}
	return (tabs->sta);
}

int	main(int ac, char **av)
{
	char	**strs;
	t_tabs	*tabs;

	tabs = ft_calloc(1, sizeof(t_tabs));
	if (ac != 2)
		exit_error("too many / few arguments");
	strs = ft_split(av[1], ' ');
	if (!strs)
		exit_error("malloc failed");
	tabs->sta = strs_to_tab(strs, tabs);
	print_tab(tabs->sta, tabs->sizea);
	if (tabs->sizea == 3)
		algo_3(tabs);
	print_tab(tabs->sta, tabs->sizea);
	return (0);
}
