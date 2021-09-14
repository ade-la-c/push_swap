/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:24:05 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/14 20:27:56 by root             ###   ########.fr       */
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

// temporary 

void	print_tab(int *tab, int tabsize, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	printf("--%s--\n", str);
	while (i < tabsize && ++j >= 0)
	{
		printf("[%d]", tab[i]);
		i++;
		if (j == 19)
		{
			printf("\n");
			j = -1;
		}
	}
	printf("\n---\n");
	return ;
}
