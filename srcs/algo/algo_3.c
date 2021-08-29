/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:23:12 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/29 16:27:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_3(t_tabs *tabs)
{
	if ((tabs->sta[0] < tabs->sta[1] && tabs->sta[1] > tabs->sta[2]
			&& tabs->sta[0] < tabs->sta[2]) || (tabs->sta[0] > tabs->sta[1]
			&& tabs->sta[1] < tabs->sta[2] && tabs->sta[0] < tabs->sta[2]) 
		|| (tabs->sta[0] > tabs->sta[1] && tabs->sta[1] > tabs->sta[2]
			&& tabs->sta[0] > tabs->sta[2]))
		action(tabs, "sa");
	if (tabs->sta[0] < tabs->sta[1] && tabs->sta[1] > tabs->sta[2]
		&& tabs->sta[0] > tabs->sta[2])
		action(tabs, "rra");
	if (tabs->sta[0] > tabs->sta[1] && tabs->sta[1] < tabs->sta[2]
		&& tabs->sta[0] > tabs->sta[2])
		action(tabs, "ra");
	return ;
}
