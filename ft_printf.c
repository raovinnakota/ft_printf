/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:23:05 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/08 17:09:32 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	ap;

	if (!fmt || !(*fmt))
		return (0);
	va_start(ap, fmt);
	len = ft_vprintf(fmt, ap);
	va_end(ap);
	return (len);
}

int		main(void)
{
	char	*test;
	char	c;
	int		testint;

	test = "test";
	testint = 5;
	c = 'r'; 
	ft_printf("This is a %s\n", test);
	ft_printf("testint is: %d\n", testint);
	//ft_printf("This is testing a characte%c", c);
	return (0);
}
