/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:23:07 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:37 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vasprintf(char **out, const char *fmt, va_list ap)
{
	t_res	*res;

	res = init_res();
	res->place = ft_strdup(fmt);
	res->flags = count_flags(res->place);
	res->next_flag = ft_strchr(res->place, '%');
	if (res->next_flag)
	{
		res->diff = ft_strndup(res->place, (res->next_flag - res->place));
		*out = ft_strdup(res->diff);
	}
	while(res->next_flag)
	{
		res->place = ft_strdup(res->next_flag + 2);
		res->flag = ft_strndup(res->next_flag, (res->place - res->next_flag));
		res->next_flag = ft_strchr(res->place, '%');
		if (res->next_flag)
		{
			res->diff = ft_strndup(res->place,(res->next_flag - res->place));
			*out = ft_strcat(*out, res->diff);
		}
		if (res->flags > 0)
		{
			handle_flags(*out, res->flag, ap);
			(res->flags)--;
		}
	}
	ft_strcat(*out, res->place);
	free(res);
	return (ft_strlen(*out));
	return (0);
}

int		ft_vprintf(const char *fmt, va_list ap)
{
	char	*out;
	int		len;

	if (!fmt || !(*fmt))
		return (0);
	len = ft_vasprintf(&out, fmt, ap);
	write(1, out, len);
	ft_strdel(&out);
	return (len);
}
