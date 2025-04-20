/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:14:03 by ainthana          #+#    #+#             */
/*   Updated: 2024/12/04 13:02:47 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_base10(long nb, char f)
{
	char	*str;
	char	*base;
	size_t	len;

	base = "0123456789";
	if (f == 'u')
		str = ft_itoa_base((unsigned int) nb, base);
	else
		str = ft_itoa_base((int) nb, base);
	if (!str)
		return (0);
	len = ft_putstr(str);
	free(str);
	return (len);
}
