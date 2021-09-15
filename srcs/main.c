/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:51:24 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/16 00:16:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_tabs *tabs, char **strs)
{
	int	i;

	i = 0;
	if (tabs->chunk)
	{
		while (--tabs->chunk > 1)
			free(tabs->chunks[tabs->chunk]);
		if (tabs->lastchunksize)
			free(tabs->chunks[tabs->chunk]);
		free(tabs->chunks[0]);
		free(tabs->chunks);
	}
	while (strs && strs[i])
	{
		free(strs[i++]);
	}
	free(strs);
	free(tabs->sta);
	free(tabs->stb);
	free(tabs);
}

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
	if (tabs->sizea <= 5)
		lil_algo(tabs);
	else
		big_algo(tabs);
	free_all(tabs, strs);
	system("leaks push_swap");
	return (0);
}

