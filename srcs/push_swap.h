/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:03:19 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/25 18:22:03 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

# include "../includes/libft/libft.h"

typedef struct s_tabs
{
	int	*sta;
	int	*stb;
}	t_tabs;

//---MAIN---//
int					main(int ac, char **av);
void				strs_to_tab(char **strs, int *tab);

//---UTILS---//
void				exit_error(char *error);
int					tabsize(int *tab);

// static int iteration = 0;
#endif
