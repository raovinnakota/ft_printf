/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:23:02 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/08 17:08:41 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_res
{
	int			flags;
	char		*place;
	char		*diff;
	char		*next_flag;
	char		*flag;
}				t_res;

int		ft_printf(const char *fmt, ...);
int		ft_vprintf(const char *fmt, va_list ap);
int		count_flags(char *fmt);

int		handle_flags(char *out, char *flag, va_list ap);

t_res	*init_res(void);
#endif
