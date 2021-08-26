/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:33:56 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/26 18:53:31 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_error(char *error)
{
	ft_putstr("ERROR : ");
	ft_putstr(error);
	ft_putchar('\n');
	exit(0);
}

// temporary

void	print_tab(int *tab, int tabsize)
{
	int	i;

	i = 0;
	while (i < tabsize)
	{
		printf("[%d]", tab[i]);
		i++;
	}
	printf("\n---\n");
	return ;
}
