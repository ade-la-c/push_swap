/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:50:05 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/26 18:52:36 by ade-la-c         ###   ########.fr       */
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
	int	sizea;
	int	*stb;
	int	sizeb;
}	t_tabs;

//---MAIN---//
int					main(int ac, char **av);

//---ACTION---//
void				action(t_tabs *tabs, char *action);

//---UTILS---//
void				exit_error(char *error);

//---ALGO---//
void				algo_3(t_tabs *tabs);


void		print_tab(int *tab, int tabsize);


// static int iteration = 0;
#endif
