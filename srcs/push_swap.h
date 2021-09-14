/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:50:05 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/14 20:36:01 by root             ###   ########.fr       */
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
# include <sys/types.h>

# include "../libft/libft.h"

typedef struct s_tabs
{
	int	*sta;
	int	*stb;
	int	**chunks;
	int	chunk;
	int	sizea;
	int	sizeb;
	int	lowa;
	int	lowb;
	int	chunksize;
	int	lastchunksize;
}	t_tabs;

//---MAIN---//

// int					main(int ac, char **av);
void				check_stack(char **strs);
int					*strs_to_tab(char **strs, t_tabs *tabs);


//---ACTION---//

void				action(t_tabs *tabs, char *action);

//---UTILS---//

void				exit_error(char *error);
int					is_in_tab(int n, int *tab, int len);

void				get_chunks(t_tabs *tabs);

//---ALGO---//

void				lil_algo(t_tabs *tabs);
void				big_algo(t_tabs *tabs);

//---CHECKER---//

void				checker(t_tabs *tabs);

void				print_tab(int *tab, int tabsize, char *str);

// static int iteration = 1;
#endif
