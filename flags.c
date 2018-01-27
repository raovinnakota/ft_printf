/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:53:20 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/26 02:01:21 by raovinnakota     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_flags(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

int		handle_flags(char *out, char *flag, va_list ap)
{
	char	*encoded;

	flag++;
	//if (*flag == 'd')
		//ft_strcat(out, ft_itoa(va_arg(ap, int)));
	//if (*flag == 'c')
		//ft_strcat(out, &(va_arg(ap, char)));
	if (!ft_isalpha(*flag))
		exit(0);
	if (*flag == 's')
		encoded = va_arg(ap, char*);
		//ft_strcat(out, va_arg(ap, char*));
	if (*flag == 'd')
		encoded = ft_itoa(va_arg(ap, int));
		//ft_strcat(out, ft_itoa(va_arg(ap, int)));
	if (*flag == 'c')
		encoded = ft_itoa(va_arg(ap, int));
		//ft_strcat(out, va_arg(ap, char));
	ft_strcat(out, encoded);
	return (1);
}
