/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:20:52 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/08 18:51:28 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	big_algo(t_tabs *tabs)
{
	int	i;

	i = 0;
	get_chunks(tabs);
	while (i < tabs->chunk - 1)
	{
		print_tab(tabs->chunks[i], tabs->sizea / tabs->chunk, "chunk");
		i++;
	}
	print_tab(tabs->chunks[i], tabs->sizea % tabs->chunk, "lastchunk");exit(0);
	return ;
}
