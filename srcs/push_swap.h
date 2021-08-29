/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:50:05 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/08/27 22:07:06 by marvin           ###   ########.fr       */
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
	int	sizea;
	int	sizeb;
	int	lowa;
	int	lowb;
}	t_tabs;

//---MAIN---//
int					main(int ac, char **av);

//---ACTION---//
void				action(t_tabs *tabs, char *action);

//---UTILS---//
void				exit_error(char *error);

//---ALGO---//
void				algo_3(t_tabs *tabs);
void				algo_5(t_tabs *tabs);


void		print_tab(int *tab, int tabsize);


// static int iteration = 0;
#endif
