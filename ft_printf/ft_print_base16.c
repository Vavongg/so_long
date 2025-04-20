/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:39:25 by ainthana          #+#    #+#             */
/*   Updated: 2024/12/04 13:02:22 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_base16(long nb, char f)
{
	char	*str;
	char	*base;
	size_t	len;

	if (f == 'x')
		base = "0123456789abcdef";
	if (f == 'X')
		base = "0123456789ABCDEF";
	str = ft_itoa_base((unsigned int) nb, base);
	if (!str)
		return (0);
	len = ft_putstr(str);
	free(str);
	return (len);
}
