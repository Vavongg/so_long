/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:32:18 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 00:32:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	return (i);
}

static size_t	ft_count_base(long long n, char	*base)
{
	size_t		i;
	long long	len_base;

	i = 1;
	len_base = ft_strlen(base);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > len_base - 1)
	{
		n = n / len_base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long n, char *base)
{
	char	*str;
	size_t	i;

	i = ft_count_base(n, base);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n > ft_strlen(base) - 1)
	{
		str[i] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		i--;
	}
	str[i] = base[n % ft_strlen(base)];
	return (str);
}
