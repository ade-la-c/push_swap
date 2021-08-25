/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:51:24 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/25 18:22:57 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strs_to_tab(char **strs, int *tab)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	tab = (int)malloc(sizeof(int) * i);
	if (!tab)
		exit_error("malloc failed");
	i = 0;
	while (strs[i] && tab[i])
	{
		tab[i] = ft_atoi(strs[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**strs;
	t_tabs	*tabs;

	if (ac != 2)
		exit_error("too many / few arguments");
	strs = ft_split(av[1], ' ');
	if (!strs)
		exit_error("malloc failed");
	strs_to_tab(strs, tabs->sta);
	if (tabsize(tabs->sta) == 3)
		algo_3(tabs);
	return (0);
}
