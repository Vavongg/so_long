/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:44:18 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 00:44:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
char	*ft_itoa_base(long long n, char *base);
char	*ft_itoa_ptr(unsigned long long n, char *base);
int		ft_strlen(char *str);
size_t	ft_print_base10(long nb, char f);
size_t	ft_print_base16(long nb, char f);
size_t	ft_print_ptr(long nb);

#endif