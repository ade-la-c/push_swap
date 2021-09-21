/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:51:24 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/21 12:57:42 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_tabs *tabs, char **strs)
{
	int	i;

	i = 0;
	if (tabs->chunk)
	{
		while (--tabs->chunk)
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

	tabs = ft_calloc(1, sizeof(t_tabs));
	if (ac < 2)
		return (0);
	if (ac > 2)
		exit_error("Error");
	strs = ft_split(av[1], ' ');
	check_stack(strs);
	if (!strs)
		exit_error("ft_split failed");
	tabs->sta = strs_to_tab(strs, tabs);
	if (check_order(tabs))
		return (0);
	if (tabs->sizea <= 5)
		lil_algo(tabs);
	else
		big_algo(tabs);
	free_all(tabs, strs);
	return (0);
}

	// system("leaks push_swap");
