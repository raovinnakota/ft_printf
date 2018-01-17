/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:01:17 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/08 16:05:59 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	*init_res(void)
{
	t_res	*res;

	res = (t_res*)malloc(sizeof(t_res));
	res->flags = 0;
	res->place = NULL;
	res->diff = NULL;
	res->next_flag = NULL;
	res->flag = NULL;
	return (res);
}
