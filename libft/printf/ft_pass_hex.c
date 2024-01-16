/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:11:33 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/16 17:09:35 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_converter_hexa_long(unsigned long number, int *count)
{
	char	*hexa_digits;

	hexa_digits = "0123456789abcdef";
	if (number >= 16)
	{
		ft_converter_hexa_long(number / 16, count);
		if (*count == -1)
			return ;
	}
	ft_putchar(hexa_digits[number % 16], count);
	if (*count == -1)
		return ;
}

void	ft_converter_hexa_min(unsigned int number, int *count)
{
	char	*hexa_digits;

	hexa_digits = "0123456789abcdef";
	if (number >= 16)
	{
		ft_converter_hexa_min(number / 16, count);
		if (*count == -1)
			return ;
	}
	ft_putchar(hexa_digits[number % 16], count);
	if (*count == -1)
		return ;
}

void	ft_converter_hexa_mayus(unsigned int number, int *count)
{
	char	*hexa_digits;

	hexa_digits = "0123456789ABCDEF";
	if (number >= 16)
	{
		ft_converter_hexa_mayus(number / 16, count);
		if (*count == -1)
			return ;
	}
	ft_putchar(hexa_digits[number % 16], count);
	if (*count == -1)
		return ;
}
