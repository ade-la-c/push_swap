/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:51:24 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/13 14:19:53 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_doubles(char **strs)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (strs && strs[i])
	{
		j = -1;
		while (strs[i] && strs[++j])
			if (ft_atoi(strs[i]) == ft_atoi(strs[j]))
				x++;
		i++;
		if (x > 1)
			exit_error("duplicate numbers aren't allowed");
		x = 0;
	}
}

static void	check_stack(char **strs)
{
	int	i;
	int	j;

	i = 0;
	if (!strs || !strs[1])
		exit_error("stack is not long enough");
	while (strs && strs[i])
	{
		j = 0;
		if (strs[i][j] == '-' || strs[i][j] == '+')
			j++;
		while (ft_isdigit(strs[i][j]))
			j++;
		if (strs[i][j])
		{
			ft_putstr("Error\n");
			exit(0);
		}
		i++;
	}
	check_doubles(strs);
}

static int	*strs_to_tab(char **strs, t_tabs *tabs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	tabs->sizea = i;
	tabs->sizeb = 0;
	tabs->sta = (int *)malloc(sizeof(int) * i);
	tabs->stb = (int *)malloc(sizeof(int) * i);
	if (!tabs->sta || !tabs->stb)
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
	check_stack(strs);
	if (!strs)
		exit_error("malloc failed");
	tabs->sta = strs_to_tab(strs, tabs);
	print_tab(tabs->sta, tabs->sizea, "sta main");
	if (tabs->sizea <= 5)
		lil_algo(tabs);
	else
		big_algo(tabs);
	print_tab(tabs->sta, tabs->sizea, "sta main end");
	return (0);
}
