/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:24:05 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/15 17:14:20 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//	exit_error is used everytime an error is expected to avoid crashing

void	exit_error(char *error)
{
	if (!ft_strcmp(error, "Error"))
		ft_putstr("Error");
	else
	{
		ft_putstr("ERROR : ");
		ft_putstr(error);
	}
	ft_putchar('\n');
	exit(0);
}

//	is_in_tab checks if a value is in a tab & returns its position

int	is_in_tab(int n, int *tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (tab[i] == n)
			return (i);
	return (-5);
}

//	check_doubles veryfies that there is no repeated numbers in the stack

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

//	check_stack veryfies that all entries in the stack are correct

void	check_stack(char **strs)
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
			exit_error("Error");
		if (ft_atoi(strs[i]) == -1 && ft_strlen(strs[i]) > 3)
			exit_error("number is too big");
		i++;
	}
	check_doubles(strs);
}

//	strs_to_tab converts an array of strings in array of numbers for later use

int	*strs_to_tab(char **strs, t_tabs *tabs)
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

// void	print_tab(int *tab, int tabsize, char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = -1;
// 	printf("--%s--\n", str);
// 	while (i < tabsize && ++j >= 0)
// 	{
// 		printf("[%d]", tab[i]);
// 		i++;
// 		if (j == 19)
// 		{
// 			printf("\n");
// 			j = -1;
// 		}
// 	}
// 	printf("\n---\n");
// 	return ;
// }
